/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilitys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:53:54 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 16:54:59 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "ft_printf.h"
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putnchar(char c, int n, int fd)
{
	while (n--)
		write(fd, &c, 1);
}

int		ft_int_dgt_cnt(intmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int		ft_float_dgt_cnt(uintmax_t n, t_arg *arg)
{
	int	ret;

	ret = (n == 0) ? (arg->precision + 1) : 0;
	while (n)
	{
		ret++;
		n /= 10;
	}
	ret++; //aggiungo lo spazzio per il punto
	ret += ((arg->neg || arg->flag_sign || arg->flag_space) ? 1 : 0);
	ret -= (!arg->flag_alt && arg->prec_set && arg->precision == 0) ? 1 : 0;
	ret += (arg->n_f > 0 && arg->n_f < 1) ? ((arg->precision - ret) + 2) : 0;
	return (ret);
}

int		ft_uint_dgt_cnt(uintmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int		ft_get_int_arg(va_list *lst)
{
	int	ret;

	ret = va_arg(*lst, int);
	return (ret);
}
