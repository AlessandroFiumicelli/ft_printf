/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:16:54 by alfiumic          #+#    #+#             */
/*   Updated: 2019/04/04 12:17:03 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"
#include <stdio.h>

/*
void	ft_shit(const char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			else if (*format + 1 ==  'c')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  'd' || *format + 1 == 'i')
			{
				int c;

				c = va_arg(args, int);
				ft_putnbr(c);
			}
			else if (*format + 1 ==  'e')
			{
				float d;

				d = va_arg(args, float);
				printf("%e", d);
			}

			else if (*format + 1 ==  'f')
			{
				double	d;

				d = va_arg(args, double);
				printf("%f", d);
			}
			else if (*format + 1 ==  'g')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  'o')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  's')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  'u')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  'x')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  'X')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  '%')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}

			else if (*format + 1 ==  'b')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  'r')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}
			else if (*format + 1 ==  'k')
			{
				int c;

				c = va_arg(args, int);
				ft_putchar(c);
			}

		}
		++format;
	}
}

int	ft_format_specifier_checker(const char *format)
{
	int	skip;
	int	stop;

	skip = 1;
	stop = 0;
	while (!stop)
	{
		if (ft_is_flag(*format))
			ft_flag_checker(*format);
		else if (ft_is_width(*format))
			ft_width_checker(*format);
		else if (ft_is_precision(*format))
			ft_precision_checker(*format);
		else if (ft_is_length(*format))
			ft_length_checker(*format);
		else if (ft_is_specifier(*format))
		{
			ft_specifier_checker(*format);
			stop = 1;
		}
		skip++;
	}
	return (skip);
}

void	ft_control_string_checker(const char *format)
{
	int	skip;

	skip = 1;
	while (*format)
	{
		if (*format == '%')
			format = format + ft_format_specifier_checker(++fomrat);
		else
			ft_putchar(*format);
		format++;
	}
}
*/

static int	ft_print_arg(char **str, va_list *lst)
{
	t_arg	arg;
	int	len;

	ft_bzero(&arg, sizeof(t_arg));
	len = ft_printf_parse_arg(*str, &arg, lst);
	ft_printf_handler(&arg, lst);
	*str += len;
	return (arg.size);
}

int	ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*cursor;
	int		out;

	cursor = (char *)format;
	out = 0;
	va_start(lst, format);
	while (*cursor)
	{
		if (*cursor == '%')
			out += ft_print_arg(&cursor, &lst);
		else
		{
			ft_putchar(*cursor++);
			out++;
		}
	}
	va_end(lst);
	return (out);
}
