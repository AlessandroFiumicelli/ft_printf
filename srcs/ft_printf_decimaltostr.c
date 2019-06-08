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

static void			putmodifiers(char *str, t_arg *arg)
{
	if (arg->neg)
		str[0] = '-';
	else
	{
		if (arg->flag_sign)
			str[0] = '+';
		else if (arg->flag_space)
			str[0] = ' ';
	}
}

void				ft_printf_decimaltostr(char *out, uintmax_t n, t_arg *arg)
{
	int	len;
	int	i;
	int	size;
	int dot;

	len = ft_float_dgt_cnt(n, arg);
	size = len;
	dot = (size - arg->precision) - 1;
	i = 0;
	putmodifiers(out, arg);
	if (n > 0 || arg->precision > 0 || arg->flag_alt)
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
