#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"

static int      ft_printf_arg(char **str, va_list *lst, int fd)
{
        t_arg   arg;
        int     len;

        ft_bzero(&arg, sizeof(t_arg));
        arg.fd = fd;
        len = ft_printf_parse_arg(*str, &arg, lst);
        ft_printf_handler(&arg, lst);
        *str += len;
        return (arg.size);
}

int	ft_printf_core(int fd, const char *format, va_list *lst)
{
	char	*cursor;
	int	out;

	cursor = (char*)format;
	out = 0;
	while (*cursor)
	{
		if (*cursor == '%')
			out += ft_printf_arg(&cursor, lst, fd);
		else
		{
			ft_putchar_fd(*cursor++, fd);
			out++;
		}
	}
	return (out);
}
