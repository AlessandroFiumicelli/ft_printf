/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:10 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 17:46:22 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"

static void	ft_padding(char c, t_arg *arg, int len)
{
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set && arg->precision > 0)
		len = ft_min(len, arg->precision);
	if (arg->width > len)
	{
		if (arg->flag_left)
		{
			ft_putchar_fd(c, arg->fd);
			ft_putnchar(fill, arg->width - len, arg->fd);
		}
		else
		{
			ft_putnchar(fill, arg->width - len, arg->fd);
			ft_putchar_fd(c, arg->fd);
		}
	}
	else
		ft_putchar_fd(c, arg->fd);
	arg->size = ft_max(len, arg->width);
}


int	ft_print_char(t_arg *arg, va_list *lst)
{
	char	c;
	size_t	len;

	if (arg->type == '%')
		c = '%';
	else
	{
		if (arg->length_mod == l)
			return (ft_print_wchar(arg, lst));
		else
			c = (char)va_arg(*lst, int);
	}
	len = 1;
	ft_padding(c, arg, len);
	return (len);
}
