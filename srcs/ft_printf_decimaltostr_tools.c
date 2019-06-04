/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimaltostr_tools.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:10:06 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 17:25:40 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_internal.h"

static char		*ft_right_field(intmax_t n)
{
	intmax_t	size;
	char		*out;

	size = ft_int_dgt_cnt(n, 10);
	if (!(out = ft_strnew(size + 1)))
		return (0);
	out[0] = '.';
	ft_memset(&out[1], 48, size - 1);
	while (out[size] != '.')
	{
		out[size] = ft_abs((n % 10)) + '0';
		n /= 10;
		size--;
	}
	return (out);
}

static char		*ft_left_field(intmax_t n)
{
	intmax_t	size;
	char		*out;

	size = ft_int_dgt_cnt(n, 10);
	if (!(out = ft_strnew(size)))
		return (0);
	while (n)
	{
		out[size-- - 1] = ft_abs((n % 10)) + '0';
		n /= 10;
	}
	return (out);
}

static intmax_t	ft_n_right(long double n, t_arg *arg)
{
	long double	num;
	intmax_t	n_right;
	intmax_t	i;
	intmax_t	inte;

	i = 0;
	inte = (intmax_t)n;
	num = n - inte;
	while (i < arg->precision)
	{
		num = num * 10;
		i++;
	}
	n_right = (intmax_t)num;
	return (n_right);
}

void			ft_printf_string_builder(char *out, long double n, t_arg *arg)
{
	intmax_t	n_left;
	intmax_t	n_right;
	char		*right_field;
	char		*left_field;
	char		*tmp;


	n_left = (intmax_t)n;
	n_right = ft_n_right(n, arg);
	right_field = ft_right_field(n_right);
	left_field = ft_left_field(n_left);
	tmp = ft_strjoin(left_field, right_field);
	out = ft_strcpy(out, tmp);
	free(tmp);
	free(right_field);
	free(left_field);
}
