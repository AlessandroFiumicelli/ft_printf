/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsignedtostr_base.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:48:17 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 16:50:36 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_internal.h"

void	ft_printf_unsignedtostr_base(char *out,\
		uintmax_t n, t_arg *arg, char *base)
{
	int	i;
	int	size;
	int	len;
	int	b;

	b = ft_strlen(base);
	len = ft_uint_dgt_cnt(n, b);
	size = ft_max(len, arg->precision);
	i = 0;
	while (i < size - len)
		out[i++] = '0';
	if (n == 0 && (arg->prec_set && arg->precision == 0))
		out[i] = '0';
	else
	{
		if (n == 0)
			out[size-- -1] = 0 + '0';
		while (n)
		{
			out[size-- - 1] = base[ft_abs((n % b))];
			n /= b;
		}
	}
}
