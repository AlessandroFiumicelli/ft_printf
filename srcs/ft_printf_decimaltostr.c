/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimaltostr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:52:00 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 16:28:15 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_internal.h"

static int		putmodifiers(char *str, long double n, t_arg *arg)
{
	if (n < 0)
		*str = '-';
	else
	{
		if (arg->flag_sign)
			*str = '+';
		else if (arg->flag_space)
			*str = ' ';
		else
			return (0);
	}
	return (1);
}

void				ft_printf_decimaltostr(char *out, uintmax_t n, t_arg *arg)
{
	int	len;
	int	index;
	int	i;
	int	size;
	int dot;

	len = ft_float_dgt_cnt(n, arg);
	size = len;
	dot = (size - arg->precision) - 1;
	i = 0;
	index = 0;
	index += putmodifiers(out + index, n, arg);
	if (n == 0 && (arg->prec_set && arg->precision == 0))
	{
		out[index] = '0';
		if (arg->flag_alt)
			out[++index] = '.';
	}
	else if (n == 0 && (arg->prec_set && arg->precision > 0))
		out[dot - 1] = '.';
	{
		out[dot] = '.';
		while (n)
		{
			if (len - 1 == dot)
				len--;
			out[len-- -1] = (n % 10) + '0';
			n /= 10;
			i++;
		}
	}
}
