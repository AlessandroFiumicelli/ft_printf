/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:59:11 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 17:59:27 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static void	ft_padding(wchar_t out, t_arg *arg, int len)
{
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set && arg->precision > 0)
		len = ft_min(len, arg->precision);
	if (arg->width > len)
	{
		if (arg->flag_left)
		{
			ft_putwchar(out);
			ft_putnchar(fill, arg->width - len);
		}
		else
		{
			ft_putnchar(fill, arg->width - len);
			ft_putwchar(out);
		}
	}
	else
		ft_putchar(out);
	arg->size = ft_max(len, arg->width);
}

int		ft_print_wchar(t_arg *arg, va_list *lst)
{
	wchar_t		c;
	size_t		len;

	len = 0;
	c = va_arg(*lst, wchar_t);
	ft_padding(c, arg, len);
	return (len);
}
