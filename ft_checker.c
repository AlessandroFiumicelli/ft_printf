/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:16:31 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/04 12:44:29 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incldue "ft_printf.h"

static int	ft_len_parser(char *str, t_arg *arg)
{

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
		if ((cnt = ft_flag_parser(str + i, arg) && (i += cnt))
			continue ;
		else if ((cnt = ft_len_parser(str + i, arg) && (i += cnt))
			continue ;
		else if ((cnt = ft_num_parser(str + i, arg, lst) && (i += cnt))
			continue
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
	arg->conversion = str[i];
	ft_parser(str + 1, arg, i - 1, lst);
	if (!str[i])
		i--;
	return (i + 1);
}
