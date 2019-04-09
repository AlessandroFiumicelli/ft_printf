#include "../libft/include/libft.h"
#include "../includes/ft_printf.h"

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
                        ft_putchar(arg->conversion);
                        ft_putnchar(fill, arg->width - len);
                }
                else
                {
                        ft_putnchar(fill, arg->width - len);
                        ft_putchar(arg->conversion);
                }
        }
        else
                ft_putchar(arg->conversion);
        arg->size = ft_max(1, arg->width);
}

int             ft_print_noconv(t_arg *arg, va_list *lst)
{
        (void)lst;
        ft_padding(arg);
        return (1);
}
}
