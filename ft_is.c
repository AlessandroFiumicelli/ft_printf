#include "ft_printf.h"

int	ft_is_flag(const char *format)
{
	if (*format == '-' || *format == '+' || *format == ' ')
		return (1);
	else if (*format == '#' || *format == '0')
		return (1);
	return (0);
}

int	ft_is_width(const char *format)
{
	if (*format == '*')
		return (1);
	else if (*format >= '0' || *format <= '9')
		return (1);
	return (0);
}


int	ft_is_precision(const char *format)
{
	if (*format == '.')
		return (1);
	return (0);
}

int	ft_is_length(const char *format)
{
	if (*format == 'h' || *format == 'l' || *format == 'L')
		return (1);
	return (0);
}


int	ft_is_specifier(const char *format)
{
	if (*format == 'c' || *format == 'd' || *format == 'i')
		return (1);
	else if (*format == 'e' || *format == 'f' || *format == 'g')
		return (1);
	else if (*format == 'G' || *format == 'o' || *format == 's')
		return (1);
	else if (*format == 'x' || *format == 'X' || *format == 'p')
		return (1);
	else if (*format == 'b' || *format == 'r' || *format == 'k')
		return (1);
	else if (*format == 'm')
		return (1);
	return (0);
}
