/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:58:05 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 17:51:19 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"

static intmax_t catch_int(t_arg *arg, va_list *lst)
{
	intmax_t	var;

	var = va_arg(*lst, intmax_t);
	if (arg->conversion == 'D')
		arg->length_mod == l;
	if (arg->length_mod == hh)
		return ((char)var);
	else if (arg->length_mod == h)
		return ((short int)var);
	else if (arg->length_mod == l)
		return ((long int)var);
	else if (arg->length_mod == ll)
		return ((long long int)var);
	else if (arg->length_mod == j)
		return ((intmax_t)var);
	else if (arg->length_mod == z)
		return ((ssize_t)var);
	return ((int)var);
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
}

int             ft_print_signed_decimal(t_arg *arg, va_list *lst)
{
	intmax_t	num;
	char		*out;
	int		len;

	num = catch_int(arg, lst);
	len = ft_max(ft_int_dgt_cnt(num, 10), arg->precision) \
	      + ((num < 0 || arg->flag_sign || arg->flag_space) ? 1 : 0);
	if (num == 0 && arg->prec_set && arg->precision == 0)
		len--;
	arg->size = ft_max(arg->fild_width, len);
	if (!(out = ft_strnew(arg->size)))
		return (0);
	if  (arg->flag_left || arg->prec_set)
		arg->flag_zero = 0;
	ft_printf_signedtostr(out + (arg->size - len), num, arg);
	ft_padding(out, len, arg);
	ft_putstr_fd(out, arg->fd);
	len = ft_strlen(out);
	free(out);
	return (len);
}
