/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:30 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/27 17:24:05 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_internal.h"

static long double catch_dec(t_arg *arg, va_list *lst)
{
	long double	var;

	var = va_arg(*lst, long double);
	if (arg->type == 'F')
		arg->length_mod = ll;
	else if (arg->length_mod == l)
		return ((double)var);
	else if (arg->length_mod == ll)
		return ((long double)var);
	return ((float)var);
}

static void	ft_padding(char *out, int len, t_arg *arg)
{
	int	offset;

	offset = 0;
	if (arg->size > len)
	{
		if (arg->flag_left)
		{
			ft_memmove(out, out + (arg->size -len), len);
			ft_memset(out + len, ' ', arg->size - len);
		}

	}
	else if (arg->flag_zero)
	{
		if (!(ft_isdigit(out[arg->size - len])))
			out[offset++] = out[arg->size - len];
		ft_memset(out + offset, '0', arg->size - len);
	}
	else
		ft_memset(out, ' ', arg->size - len);
}

int             ft_printf_decimal(t_arg *arg, va_list *lst)
{
	long double	num;
	char		*out;
	int		len;

	num = catch_dec(arg, lst);
	len = ft_max(ft_dec_dgt_cnt(num, arg), arg->precision) \
	      + ((num < 0 || arg->flag_sign || arg->flag_space) ? 1 : 0);
	if (num == 0 && arg->prec_set && arg->precision == 0)
		len--;
	arg->size = ft_max(arg->width, len);
	if (!(out = ft_strnew(arg->size)))
		return (0);
	if  (arg->flag_left || arg->prec_set)
		arg->flag_zero = 0;
	ft_printf_decimaltostr(out + (arg->size - len), num, arg);
	ft_padding(out, len, arg);
	ft_putstr_fd(out, arg->fd);
	len = ft_strlen(out);
	free(out);
	return (len);
}
