/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:28:47 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 16:29:50 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# include <stdarg.h>
# include <stdint.h>

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
		ll,
		j,
		z
	}		length_mod;
	char	type;
	int		fd;
	int		size;
}				t_arg;

int				ft_printf_parse_arg(char *str, t_arg *arg, va_list *lst);
int				ft_printf_handler(t_arg *arg, va_list *lst);
/*
** Handlers
*/
int				ft_printf_signed_decimal(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_decimal(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_octal(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_hexa(t_arg *arg, va_list *lst);
int				ft_printf_decimal(t_arg *arg, va_list *lst);
int				ft_printf_string(t_arg *arg, va_list *lst);
int				ft_printf_wstring(t_arg *arg, va_list *lst);
int				ft_printf_char(t_arg *arg, va_list *lst);
int				ft_printf_wchar(t_arg *arg, va_list *lst);
int				ft_printf_noconv(t_arg *arg, va_list *lst);
int				ft_printf_float(t_arg *arg, va_list *lst);
int				ft_printf_binary(t_arg *arg, va_list *lst);
int				ft_printf_scientific(t_arg *arg, va_list *lst);
int				ft_printf_date(t_arg *arg, va_list *lst);
/*
** Conversion
*/
void			ft_printf_signedtostr(char *out, intmax_t num, t_arg *arg);
void			ft_printf_unsignedtostr_base(char *out, uintmax_t num, \
					t_arg *arg, char *base);
void			ft_printf_decimaltostr(char *out, long double n, t_arg *arg);
void			ft_printf_string_builder(char *out, long double n, t_arg *arg);
/*
** Utilities
*/
void			ft_putnchar(char c, int n, int fd);
int				ft_int_dgt_cnt(intmax_t n, int base);
int				ft_uint_dgt_cnt(uintmax_t n, int base);
int				ft_dec_dgt_cnt(long double n, t_arg *arg);
int				ft_get_int_arg(va_list *lst);

#endif
