/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilitys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:53:54 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 15:56:20 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_internal.h"
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putnchar(char c, int n, int fd)
{
	while (n--)
		write(fd, &c, 1);
}

int	ft_int_dgt_cnt(intmax_t n, int base)
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

int	ft_uint_dgt_cnt(uintmax_t n, int base)
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

int	ft_get_int_arg(va_list *lst)
{
	int	ret;

	ret = va_arg(*lst, int);
	return (ret);
}
