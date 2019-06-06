/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:44:52 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 15:51:39 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_internal.h"

static long double	catch_dec(t_arg *arg, va_list *lst)
{
	long double	num;
	int					i;

	i = 0;
	num = 0;
	if (arg->type == 'F')
		arg->length_mod = ll;
	if (arg->length_mod == l)
		num = (double)va_arg(*lst, double);
	else if (arg->length_mod == ll)
		num = (long double)va_arg(*lst,  long double);
	num = (double)va_arg(*lst, double);
	arg->precision = (!arg->prec_set) ? 6 : arg->precision;
	arg->n_f = (long double)(num < 0) ? -num : num;
	while (i < arg->precision)
	{
		num = num * 10;
		i++;
	}
	if (num < 0)
	{
		num *= -1;
		arg->neg = 1;
	}
	return (num);
}

static void			ft_padding(char *out, int len, t_arg *arg)
{
	int	offset;

	offset = 0;
	if (arg->size > len)
	{
		if (arg->flag_left)
		{
			ft_memmove(out, out + (arg->size - len), len);
			ft_memset(out + len, ' ', arg->size - len);
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
}

int					ft_printf_decimal(t_arg *arg, va_list *lst)
{
	long double	num;
	uintmax_t		n;
	char		*out;
	int			len;

	num = catch_dec(arg, lst);
	n = (uintmax_t)(num + 0.5);
	len = ft_float_dgt_cnt(n, arg);
	arg->size = ft_max(arg->width, len);
	if (!(out = ft_strnew(arg->size)))
		return (0);
	if (arg->flag_left || arg->prec_set)
		arg->flag_zero = 0;
	ft_memset(out, 48, arg->size);
	ft_printf_decimaltostr(out + (arg->size - len), n, arg);
	ft_padding(out, len, arg);
	ft_putstr_fd(out, arg->fd);
	len = ft_strlen(out);
	free(out);
	return (len);
}
