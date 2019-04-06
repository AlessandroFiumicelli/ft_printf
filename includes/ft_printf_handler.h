
#ifndef FT_PRINTF_HANDLER_H
# define FT_PRINTF_HANDLER_H
# include "ft_printf.h"

typedef int		(*t_func)(t_arg*, va_list*);

typedef struct		s_handler
{
	char	conv;
	t_func	f;
}			t_handler;

t_handler		c_table[]
{
	{'%', &ft_putchar},
	{'c', &ft_putchar},
	{'C', &ft_putchar},
	{'d', &ft_putchar},
	{'i', &ft_putchar},
	{'e', &ft_putchar},
	{'E', &ft_putchar},
	{'f', &ft_putchar},
	{'g', &ft_putchar},
	{'G', &ft_putchar},
	{'o', &ft_putchar},
	{'s', &ft_putchar},
	{'S', &ft_putchar},
	{'u', &ft_putchar},
	{'U', &ft_putchar},
	{'x', &ft_putchar},
	{'X', &ft_putchar},
	{'p', &ft_putchar},
	{'b', &ft_putchar},
	{'r', &ft_putchar},
	{'k', &ft_putchar},
	{0, 0}
};

#endif
