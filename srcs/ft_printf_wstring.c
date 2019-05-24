/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:59:22 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 17:53:24 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"

static void		putnwstr(const wchar_t *str, size_t size, int fd)
{
	while (size--)
		ft_putwchar_fd(*str++, fd);
}

static int		getwlen(const wchar_t *cur, int *size)
{
	int	idx;
	int	len;
	int	tmp;

	len = 0;
	idx = 0;
	while (cur[idx])
	{
		if (cur[idx] < 0x80)
			tmp = 1;
		else if (cur[idx] < 0x800)
			tmp = 2;
		else if (cur[idx] < 0x10000)
			tmp = 3;
		else if (cur[idx] <= 0x10ffff)
			tmp = 4;
		else
			tmp = 0;
		if ((len + tmp > (*size)) && ((*size = len) + 1))
			return (idx);
		len += tmp;
		idx++;
	}
	return (idx);
}

static void		ft_padding(const wchar_t *out, t_arg *arg, int len)
{
	int		wch;

	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	wch = getwlen(out, &len);
	if (arg->width > len)
	{
		if (arg->flag_left)
		{
			putnwstr(out, wch, arg->fd);
			ft_putnchar(' ', arg->width - len, arg->fd);
		}
		else
		{
			ft_putnchar(' ', arg->width - len, arg->fd);
			putnwstr(out, wch, arg->fd);
		}
	}
	else
		putnwstr(out, wch, arg->fd);
	arg->size = ft_max(len, arg->width);
}

int				ft_printf_wstring(t_arg *arg, va_list *lst)
{
	const wchar_t	*str;
	const wchar_t	*cur;
	size_t			len;

	str = va_arg(*lst, wchar_t*);
	len = 0;
	if (str == 0)
		str = L"(null)";
	cur = str;
	while (*cur)
	{
		if (*cur < 0x80)
			len += 1;
		else if (*cur < 0x800)
			len += 2;
		else if (*cur < 0x10000)
			len += 3;
		else if (*cur <= 0x10ffff)
			len += 4;
		else
			len = 0;
		cur++;
	}
	ft_padding(str, arg, len);
	return (len);
}
