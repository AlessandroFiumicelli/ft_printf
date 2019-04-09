#include "../libft/include/libft.h"
#include "../includes/ft_printf.h"

static void	ft_padding(char c, t_arg *arg, size_t len)
{
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set && arg->precision > 0)
		len = ft_min(len, arg->precision);
	if (arg->width > len)
	{
		if (arg->flag_left)
		{
			ft_putchar(c);
			ft_putnchar(fill, arg->width - len);
		}
		else
		{
			ft_putnchar(fill, arg->width - len);
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
	arg->size = ft_max(len, width);
}


int	ft_print_char(t_arg *arg, va_list *lst)
{
	char	c;
	size_t	len;

	if (arg->type == '%')
		c = '%';
	else
	{
		if (arg->length_mod == 'l')
			return (ft_print_wchar(t_arg *arg, va_list *lst));
		else
			c = (char)va_arg(*lst, int);
	}
	len = 1;
	ft_padding(c, arg, len);
	return (len);
}
