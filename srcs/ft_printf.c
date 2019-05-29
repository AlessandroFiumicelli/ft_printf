/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:16:54 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 15:35:50 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_internal.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int		out;

	va_start(lst, format);
	out = ft_printf_core(1, format, &lst);
	va_end(lst);
	return (out);
}
