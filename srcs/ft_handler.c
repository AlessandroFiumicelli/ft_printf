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

#include "../includes/ft_printf_handler.h"
#include "../libft/include/libft.h"

extern t_handler	c_table[23];

int	ft_printf_handler(t_arg *arg, va_list *lst)
{
	int			i;

	i = 0;
	while (c_table[i].conv != 0)
	{
		if (c_table[i].conv == arg->type)
			return (c_table[i].f(arg, lst));
		i++;
	}
	if (arg->type)
		ft_print_noconv(arg, lst);
	return (0);
}
