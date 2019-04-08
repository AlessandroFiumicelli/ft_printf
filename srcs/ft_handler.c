
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_handler.h"

extern t_handler	c_table[];

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
