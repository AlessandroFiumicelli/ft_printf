/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_noconv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:42 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/09 17:55:06 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"

static void     ft_padding(t_arg *arg)
{
        char    fill;
        int     len;

        fill = arg->flag_zero ? '0' : ' ';
        len = 1;
        if (arg->prec_set && arg->precision > 1)
                len = ft_min(1, arg->precision);
        if (arg->width > 1)
        {
                if (arg->flag_left)
                {
                        ft_putchar_fd(arg->type, arg->fd);
                        ft_putnchar(fill, arg->width - len, arg->fd);
                }
                else
                {
                        ft_putnchar(fill, arg->width - len, arg->fd);
                        ft_putchar_fd(arg->type, arg->fd);
                }
        }
        else
                ft_putchar_fd(arg->type, arg->fd);
        arg->size = ft_max(1, arg->width);
}

int             ft_printf_noconv(t_arg *arg, va_list *lst)
{
        (void)lst;
        ft_padding(arg);
        return (1);
}
