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

static int		getlen(int len, long double n, t_arg *arg)
{
	len = ft_max(len, arg->precision);
	if (n < 0 || arg->flag_space || arg->flag_sign)
		len++;
	return (len);
}

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

void			ft_printf_decimaltostr(char *out, long double n, t_arg *arg)
{
	int	size;
	int	len;
	int	index;

	len = ft_dec_dgt_cnt(n, arg);
	size = getlen(len, n, arg);
	index = 0;
	index += putmodifiers(out + index, n, arg);
	while (index < size - len)
		out[index++] = '0';
	if (n == 0 && !(arg->prec_set && arg->precision == 0))
		out[index] = '0';
	else
		ft_printf_string_builder(out, n, arg);
}
