#include <stdint.h>
#include "../libft/include/libft.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_internal.h"

static char     *ft_right_field(intmax_t n)
{
        intmax_t        size;
        char            *out;

        size = ft_int_dgt_cnt(n, 10);
        if (!(out = ft_strnew(size + 1)))
                return (0);
        while (n)
        {
                out[size-- -1] = ft_abs((n % 10)) + '0';
                n /= 10;
        }
	out[0] = '.';
	return (out);
}

static char     *ft_left_field(intmax_t n)
{
        intmax_t        size;
        char            *out;

        size = ft_int_dgt_cnt(n, 10);
        if (!(out = ft_strnew(size)))
                return (0);
        while (n)
        {
                out[size-- -1] = ft_abs((n % 10)) + '0';
                n /= 10;
        }
	return (out);
}

static intmax_t	ft_n_right(long double n, t_arg *arg)
{
	long double	num;
	intmax_t	n_right;
	intmax_t	i;
	intmax_t	inte;

	i = 0;
	inte = (intmax_t)n;
	num = n - inte;
	while (i < arg->precision)
	{
		num = num * 10;
		i++;
	}
	n_right = (intmax_t)num;
	return (n_right);
}

static void	ft_string_builder(char *out, long double n, t_arg *arg)
{
	intmax_t	n_left;
	intmax_t	n_right;
	char		*right_field;
	char		*left_field;
	char		*tmp;

	n_left = (intmax_t)n;
	n_right = ft_n_right(n, arg);
	right_field = ft_right_field(n_right);
	left_field = ft_left_field(n_left);
	tmp = ft_strjoin(left_field, right_field);
	out = strcpy(out, tmp);
	free(tmp);
	free(right_field);
	free(left_field);
}

static int      getlen(int len, long double n, t_arg *arg)
{
        len = ft_max(len, arg->precision);
        if(n < 0 || arg->flag_space || arg->flag_sign)
                len++;
        return (len);
}

static int      putmodifiers(char *str, long double n, t_arg *arg)
{
        if (n < 0)
                *str = '-';
        else
        {
                if (arg->flag_sign)
                        *str = '+';
                else if (arg->flag_space)
                        *str = ' ';
                else
                        return (0);
        }
        return (1);
}
void            ft_printf_decimaltostr(char *out, long double n, t_arg *arg)
{
        int     size;
        int     len;
        int     index;

        len = ft_dec_dgt_cnt(n, arg);
        size = getlen(len, n, arg);
        index = 0;
        index += putmodifiers(out + index, n, arg);
        while (index < size -len)
                out[index++] = '0';
        if (n == 0 && !(arg->prec_set  && arg->precision == 0))
                out[index] = '0';
        else
		ft_string_builder(out, n, arg);
}
