/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:08:47 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 18:11:42 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HANDLER_H
# define FT_PRINTF_HANDLER_H
# include "ft_printf.h"

typedef int		(*t_func)(t_arg*, va_list*);

typedef struct	s_handler
{
	char	conv;
	t_func	f;
}				t_handler;

t_handler		c_table[23] =
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

#endif
