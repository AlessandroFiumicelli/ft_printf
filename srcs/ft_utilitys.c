
#include "../includes/ft_printf.h"
#include "../libft/include/libft.h"

void	ft_putnchar(char c, size_t n)
{
	while (n--)
		write(1, &c, 1);
}

int	ft_int_dgt_cnt(intmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int	ft_uint_dgt_cnt(uintmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int	ft_get_int_arg(va_list *lst)
{
	int	ret;

	ret = va_arg(*lst, int);
	return (ret);
}
