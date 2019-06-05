// #include "ft_printf.h"
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	ft_printf("\n");
	ft_printf("# 0194 ft_printf(f, 3.14):\n");
	ft_printf("- ft_printf:%f\n", 3.14);
	printf("-    printf:%f\n", 3.14);

	ft_printf("\n");
	ft_printf("# 0195 ft_printf(f, 0.0):\n");
	ft_printf("- ft_printf:%f\n", 0.0);
	printf("-    printf:%f\n", 0.0);

	ft_printf("\n");
	ft_printf("# 0196 ft_printf(.f .0f, 0.0, 0.0):\n");
	ft_printf("- ft_printf:%.f %.0f\n", 0.0, 0.0);
	printf("-    printf:%.f %.0f\n", 0.0, 0.0);

	ft_printf("\n");
	ft_printf("# 0197 ft_printf(5.f 5.0f, 0.0, 0.0):\n");
	ft_printf("- ft_printf:%5.f %5.0f\n", 0.0, 0.0);
	printf("-    printf:%5.f %5.0f\n", 0.0, 0.0);

	ft_printf("\n");
	ft_printf("# 0198 ft_printf(#6.f #6.0f, 0.0, 0.0):\n");
	ft_printf("- ft_printf:%#6.f %#6.0f\n", 0.0, 0.0);
	printf("-    printf:%#6.f %#6.0f\n", 0.0, 0.0);

	ft_printf("\n");
	ft_printf("# 0199 ft_printf(-2.2f 10.2f, 3.14, 3.14):\n");
	ft_printf("- ft_printf:%-2.2f %10.2f\n", 3.14, 3.14);
	printf("-    printf:%#2.2f %10.2f\n", 3.14, 3.14);

	ft_printf("\n");
	ft_printf("# 0200 ft_printf(#6.f #6.0f, 3.14, 3.14):\n");
	ft_printf("- ft_printf:%#6.f %#6.0f\n", 0.0, 0.0);
	printf("-    printf:%#6.f %#6.0f\n", 0.0, 0.0);

	ft_printf("\n");
	ft_printf("# 0201 ft_printf(6.f 6.0f, 0.0314, 0.0314):\n");
	ft_printf("- ft_printf:%f %f\n", 0.0314, 0.0314);
	printf("-    printf:%f %f\n", 0.0314, 0.0314);
	return (0);

}
