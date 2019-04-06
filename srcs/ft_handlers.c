
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_handler.h"

int	ft_printf_handler(t_arg *arg, va_list *lst)
{
	int	i;

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

?
