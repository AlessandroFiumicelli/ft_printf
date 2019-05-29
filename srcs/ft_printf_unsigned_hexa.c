/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_hexa.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:58:46 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 16:47:45 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_internal.h"

static uintmax_t	catch_int(t_arg *arg, va_list *lst)
{
	uintmax_t	var;

	var = va_arg(*lst, uintmax_t);
	if (arg->type == 'p' && (arg->flag_alt = 1))
		return ((uintmax_t)(uintptr_t)var);
	else if (arg->length_mod == hh)
		return ((unsigned char)var);
	else if (arg->length_mod == h)
		return ((unsigned short int)var);
	else if (arg->length_mod == l)
		return ((unsigned long int)var);
	else if (arg->length_mod == ll)
		return ((unsigned long long int)var);
	else if (arg->length_mod == j)
		return ((uintmax_t)var);
	else if (arg->length_mod == z)
		return ((size_t)var);
	return ((unsigned int)var);
}

static char			*getprefix(t_arg *arg)
{
	if (arg->flag_alt)
	{
		if (arg->type == 'x' || arg->type == 'p')
			return ("0x");
		else if (arg->type == 'X')
			return ("0X");
	}
	return ("");
}

static void			ft_padding(char *out, int len, t_arg *arg, uintmax_t num)
{
	int	offset;

	offset = ft_strlen(getprefix(arg));
	if (!num && arg->type != 'p')
		offset = 0;
	if ((arg->flag_alt && len) || arg->type == 'p')
	{
		ft_memcpy(out + (arg->size - len - offset), getprefix(arg), offset);
		len += offset;
	}
	if (arg->size > len)
	{
		if (arg->flag_left)
		{
			ft_memmove(out, out + (arg->size - len), len);
			ft_memset(out + len, ' ', arg->size - len);
		}
		else if (arg->flag_zero)
		{
			ft_memmove(out, out + (arg->size - len), offset);
			ft_memset(out + offset, '0', arg->size - len);
		}
		else
			ft_memset(out, ' ', arg->size - len);
	}
}

static char			*getb(t_arg *arg)
{
	if (arg->type == 'x' || arg->type == 'p')
		return ("0123456789abcdef");
	else if (arg->type == 'X')
		return ("0123456789ABCDEF");
	else
		return (0);
}

int					ft_printf_unsigned_hexa(t_arg *arg, va_list *lst)
{
	uintmax_t	num;
	char		*out;
	int			len;

	num = catch_int(arg, lst);
	if (arg->flag_left)
		arg->flag_zero = 0;
	len = ft_max(ft_uint_dgt_cnt(num, 16), arg->precision);
	if (num == 0 && arg->prec_set && arg->precision == 0)
		len--;
	arg->size = ft_max(arg->width, len + \
	((num || arg->type == 'p') ? ft_strlen(getprefix(arg)) : 0));
	if (!(out = ft_strnew(arg->size)))
		return (0);
	ft_printf_unsignedtostr_base(out + (arg->size - len), num, arg, getb(arg));
	ft_padding(out, len, arg, num);
	len = ft_strlen(out);
	ft_putstr_fd(out, arg->fd);
	free(out);
	return (len);
}
