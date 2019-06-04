/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_zero_cases_f.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:52:00 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 16:28:15 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_internal.h"

void ft_printf_zero_cases_f(char *out, long double n, t_arg *arg, int index)
{
	 if (n == 0 && (arg->prec_set && arg->precision == 0))
    {
      if (arg->flag_alt)
      {
        out[index] = '0';
        out[++index] = '.';
      }
      else
        out[index] = '0';
    }

}
