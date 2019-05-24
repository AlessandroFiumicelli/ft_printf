/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:58:17 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 17:52:11 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"

static void	ft_padding(const char *out, t_arg *arg, int len)
{
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	if (arg->width > len)
	{
		if (arg->flag_left)
		{
			write(arg->fd, out, len);
			ft_putnchar(fill, arg->width - len, arg->fd);
		}
		else
		{
			ft_putnchar(fill, arg->width - len, arg->fd);
			write(arg->fd, out, len);
		}
	}
	else
		write(arg->fd, out, len);
	arg->size = ft_max(len, arg->width);
}

int		ft_printf_string(t_arg *arg, va_list *lst)
{
	const char	*str;
	size_t		len;

	if (arg->length_mod == l)
		return (ft_printf_wstring(arg, lst));
	str = va_arg(*lst, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	ft_padding(str, arg, len);
	return (len);
}
