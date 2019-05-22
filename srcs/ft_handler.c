/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:56:43 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 18:11:39 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"
#include "../includes/ft_printf_handler.h"

static t_handler	g_table[] =
{
        {'%', &ft_print_char},
        {'c', &ft_print_char},
        {'C', &ft_print_wchar},
        {'d', &ft_print_signed_decimal},
        {'i', &ft_print_signed_decimal},
        {'e', &ft_print_scientific},
        {'E', &ft_print_scientific},
        {'f', &ft_print_float},
        {'g', &ft_print_scientific},
        {'G', &ft_print_scientific},
        {'o', &ft_print_unsigned_octal},
        {'O', &ft_print_unsigned_octal},
        {'s', &ft_print_string},
        {'S', &ft_print_wstring},
        {'u', &ft_print_unsigned_decimal},
        {'U', &ft_print_unsigned_decimal},
        {'x', &ft_print_unsigned_hexa},
        {'X', &ft_print_unsigned_hexa},
        {'p', &ft_print_unsigned_hexa},
        {'b', &ft_print_binary},
        {'r', &ft_print_unsigned_hexa},
        {'k', &ft_print_date},
        {0, 0}
};

int	ft_printf_handler(t_arg *arg, va_list *lst)
{
	int			i;

	i = 0;
	while (g_table[i].conv != 0)
	{
		if (g_table[i].conv == arg->type)
			return (g_table[i].f(arg, lst));
		i++;
	}
	if (arg->type)
		ft_print_noconv(arg, lst);
	return (0);
}
