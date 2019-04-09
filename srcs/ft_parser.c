/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:16:31 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/04 18:43:53 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/include/libft.h"

static int	ft_num_parser(char *str, t_arg *arg, va_list *lst)
{
	if (*str == '.')
	{
		arg->prec_set = 1;
		arg->precision = (str[1] == '*') ? ft_get_int_arg(lst) : ft_atoi(str);
		arg->precision = (arg->precision < 0) ? 0 : arg->precision;
		return (1 + ft_int_dgt_cnt(arg->precision, 10) - ft_isdigit(str[1]) ? 0 : 1);
	}
	else if (ft_isdigit(*str) || *str == '*')
	{
		arg->width = (str[1] == '*') ? ft_get_int_arg(lst) : ft_atoi(str);
		if (arg->width < 0 && (arg->width = ft_abs(arg->width)))
			arg->flag_left = 1;
		return (ft_int_dgt_cnt(arg->width, 10));
	}
	return (0);
}

static int	ft_len_parser(char *str, t_arg *arg)
{
	if (*str == 'h' && *(str + 1) == 'h')
	{
		arg->length_mod = ft_max(arg->length_mod, hh);
		return (2);
	}
	else if (*str == 'l' && *(str + 1) == 'l')
	{
		arg->length_mod = ft_max(arg->length_mod, ll);
		return (2);
	}
	else if (*str == 'h' || *str == 'l')
	{
		if (*str == 'h')
			arg->length_mod = ft_max(arg->length_mod, h);
		else if (*str == 'l')
			arg->length_mod = ft_max(arg->length_mod, l);
		return (1);
	}
	return (0);
}

static int	ft_flag_parser(char *str, t_arg *arg)
{
	if (*str =='#')
		arg->flag_alt = 1;
	else if (*str == '0')
		arg->flag_zero = 1;
	else if (*str == '-')
		arg->flag_left = 1;
	else if (*str == ' ')
		arg->flag_space = 1;
	else if (*str == '+')
		arg->flag_sign = 1;
	else
		return (0);
	return (1);
}

static int	ft_parser(char *str, t_arg *arg, int len, va_list *lst)
{
	int		i;
	int		cnt;

	i = 0;
	while (i < len)
	{
		if ((cnt = ft_flag_parser(str + i, arg) && (i += cnt)))
			continue ;
		else if ((cnt = ft_len_parser(str + i, arg) && (i += cnt)))
			continue ;
		else if ((cnt = ft_num_parser(str + i, arg, lst) && (i += cnt)))
			continue ;
		return (0);
	}
	if (arg->flag_left)
		arg->flag_zero = 0;
	return (1);
}

int			ft_printf_parse_arg(char *str, t_arg *arg, va_list *lst)
{
	int		i;
	int		isconv;

	i = 1;
	isconv = 1;
	while (str[i] && !ft_strchr(FT_PRINTF_TYPE, str[i]))
	{
		if (!ft_strchr(FT_PRINTF_CONVERSION, str[i] && !(isconv = 0)))
			break ;
		i++;	
	}
	arg->type = str[i];
	ft_parser(str + 1, arg, i - 1, lst);
	if (!str[i])
		i--;
	return (i + 1);
}
