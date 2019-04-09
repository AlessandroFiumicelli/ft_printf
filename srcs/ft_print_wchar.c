
#include "../includes/ft_printf.h"


static void	ft_padding(wchar_t out, t_arg *arg, size_t len)
{
	char	fill;

	fill = arg-flag_zero ? '0' : ' ';
	if (arg->prec_set && arg->precison > 0)
		len = ft_min(len, arg->precision);
	if (arg->width > len)
	{
		if (arg->flag_left)
		{
			ft_putchar(out);
			ft_putnchar(fill, arg->width - len);
		}
		else
		{
			ft_putnchar(fill, arg->width - len);
			ft_putchar(out);
		}
	}
	else
		ft_putchar(out);
	arg->size = ft_max(len, arg->width;
}

int		ft_print_wchar(t_arg *arg, va_list *lst)
{
	wchar_t		c;
	size_t		len;

	c = va_arg(*lst, wchar_t);
	ft_padding(c, arg, len);
	return (len);
}
