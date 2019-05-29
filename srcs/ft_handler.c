/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:56:43 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 15:25:54 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"
#include "ft_printf_handler.h"

static t_handler	g_table[] =
{
	{'%', &ft_printf_char},
	{'c', &ft_printf_char},
	{'C', &ft_printf_wchar},
	{'d', &ft_printf_signed_decimal},
	{'i', &ft_printf_signed_decimal},
	{'e', &ft_printf_scientific},
	{'E', &ft_printf_scientific},
	{'f', &ft_printf_decimal},
	{'g', &ft_printf_scientific},
	{'G', &ft_printf_scientific},
	{'o', &ft_printf_unsigned_octal},
	{'O', &ft_printf_unsigned_octal},
	{'s', &ft_printf_string},
	{'S', &ft_printf_wstring},
	{'u', &ft_printf_unsigned_decimal},
	{'U', &ft_printf_unsigned_decimal},
	{'x', &ft_printf_unsigned_hexa},
	{'X', &ft_printf_unsigned_hexa},
	{'p', &ft_printf_unsigned_hexa},
	{'b', &ft_printf_binary},
	{'r', &ft_printf_unsigned_hexa},
	{'k', &ft_printf_date},
	{0, 0}
};

int					ft_printf_handler(t_arg *arg, va_list *lst)
{
	int	i;

	i = 0;
	while (g_table[i].conv != 0)
	{
		if (g_table[i].conv == arg->type)
			return (g_table[i].f(arg, lst));
		i++;
	}
	if (arg->type)
		ft_printf_noconv(arg, lst);
	return (0);
}
