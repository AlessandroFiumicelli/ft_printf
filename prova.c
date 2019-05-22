#include "includes/ft_printf.h"
#include "includes/ft_printf_handler.h"
#include "includes/ft_printf_internal.h"
#include <stdio.h>

int	main()
{
	printf("%-8c\n", 'a');
	ft_printf("%-8c\n", 'a');
	return (0);
}
