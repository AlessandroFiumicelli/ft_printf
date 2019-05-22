
#include <stdint.h>
#include "../libft/include/libft.h"
#include "../includes/ft_printf_internal.h"

void	ft_printf_unsignedtostr_base(char *out, uintmax_t n, t_arg *arg, char *base)
{
	int	i;
	int	size;
	int	len;
	int	b;

	b = ft_strlen(base);
	len = ft_uint_dgt_cnt(n, b);
	size = ft_max(len, arg->precision);
	i = 0;
	while (i < size - len)
		out[i++] = '0';
	if (n == 0 && (arg->prec_set && arg->precision == 0))
		out[i] = '0';
	else
	{
		while (n)
		{
			out[size-- -1] = base[ft_abs((n % b))];
			n /= b;
		}
	}
}
