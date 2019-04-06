/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:17:37 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/04 18:09:18 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft/include/libft.h"
# define FT_PRINTF_TYPE "%cCdiIefgGosSuUxXpbrk"
# define FT_PRINTF_CONVERSION "#0-+ *.%cCdiIefgGosSuUxXpbrkhlL0123456789"

int				ft_printf(const char *format, ...);

typedef struct	s_arg
{
	int		flag_alt;
	int		flag_zero;
	int		flag_left;
	int		flag_space;
	int		flag_sign;
	int		width;
	int		prec_set;
	int		precision;
	enum
	{
		none,
		hh,
		h,
		l,
		ll
	}		lenth_mod;
	char		type;
	int		size;
}				t_arg;

int				ft_printf_parse_arg(char *str, t_arg *arg, va_list *lst);
int				ft_printf_handler(t_arg *arg, va_list *lst);

// Handlers

int				ft_print_char(t_arg *arg, va_list *lst)
int				ft_print_wchar(t_arg *arg, va_list *lst);
int				ft_print_string(t_arg *arg, va_list *lst);
int				ft_print_wstring(t_arg *arg, va_list *lst);
int				ft_print_signed_decimal(t_arg *arg, va_list *lst);
int				ft_print_unsigned_decimal(t_arg *arg, va_list *lst);
int				ft_print_unsigned_octal(t_arg *arg, va_list *lst);
int				ft_print_unsigned_hexa(t_arg *arg, va_list *lst);
int				ft_print_noconv(t_arg *arg, va_list *lst);

// Conversion

// Utilities
int				ft_int_dgt_cnt(intmax_t n, int base);
int				ft_uint_dgt_cnt(uintmax_t n, int base);
int				ft_get_int_arg(va_list *lst);

#endif
