/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:21:49 by alfiumic          #+#    #+#             */
/*   Updated: 2019/05/29 17:22:04 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("# 0014 ft_printf(x, 0)\n");
	ft_printf("- ft_printf:%x\n", 0);
	printf("-    printf:%x\n", 0);

	ft_printf("\n");
	ft_printf("# 0015 ft_printf(X, 0):\n");
	ft_printf("- ft_printf:%X\n", 0);
	printf("-    printf:%X\n", 0);

	ft_printf("\n");
	ft_printf("# 0018 ft_printf(x, 4294967296):\n");
	ft_printf("- ft_printf:%x\n", 4294967296);
	printf("-    printf:%x\n", 4294967296);

	ft_printf("\n");
	ft_printf("# 0019 ft_printf(X, 4294967296):\n");
	ft_printf("- ft_printf:%X\n", 4294967296);
	printf("-    printf:%X\n", 4294967296);

	ft_printf("\n");
	ft_printf("# 0025 ft_printf(hx, 4294967296):\n");
	ft_printf("- ft_printf:%hx\n", 4294967296);
	printf("-    printf:%x\n", 4294967296);

	ft_printf("\n");
	ft_printf("# 0026 ft_printf(hhX, 4294967296):\n");
	ft_printf("- ft_printf:%hhX\n", 4294967296);
	printf("-    printf:%hhX\n", 4294967296);

	ft_printf("\n");
	ft_printf("# 0028 ft_printf(jx, 4294967296):\n");
	ft_printf("- ft_printf:%jx\n", 4294967296);
	printf("-    printf:%jx\n", 4294967296);

	ft_printf("\n");
	ft_printf("# 0040 ft_printf(#x, 0):\n");
	ft_printf("- ft_printf:%#x\n", 0);
	printf("-    printf:%#x\n", 0);

	ft_printf("\n");
	ft_printf("# 0046 ft_printf(#.x #.0x, 0, 0):\n");
	ft_printf("- ft_printf:%#.x %#.0x\n", 0, 0);
	printf("-    printf:%#.x %#.0x\n", 0, 0);

	ft_printf("\n");
	ft_printf("# 0047 ft_printf(.x .0x, 0):\n");
	ft_printf("- ft_printf:%.x %.0x\n", 0, 0);
	printf("-    printf:%.x %.0x\n", 0, 0);

	ft_printf("\n");
	ft_printf("# 0048 ft_printf(5.x 5.0x, 0, 0):\n");
	ft_printf("- ft_printf:%5.x %5.0x\n", 0, 0);
	printf("-    printf:%5.x %5.0x\n", 0, 0);

	ft_printf("\n");
	ft_printf("# 0092 ft_printf(o, 0):\n");
	ft_printf("- ft_printf:%o\n", 0);
	printf("-    printf:%o\n", 0);

	ft_printf("\n");
	ft_printf("# 0093 ft_printf(.o .0o, 0, 0):\n");
	ft_printf("- ft_printf:%.o %.0o\n", 0, 0);
	printf("-    printf:%.o %.0o\n", 0, 0);

	ft_printf("\n");
	ft_printf("# 0094 ft_printf(5.o 5.0o, 0, 0):\n");
	ft_printf("- ft_printf:%5.o %5.o\n", 0, 0);
	printf("-    printf:%5.o %5.0o\n", 0, 0);

	ft_printf("\n");
	ft_printf("# 0095 ft_printf(#.o #.0o, 0, 0):\n");
	ft_printf("- ft_printf:%#.o %#.0o\n", 0, 0);
	printf("-    printf:%#.o %#.0o\n", 0, 0);

	ft_printf("\n");
	ft_printf("# 0127 ft_printf(5d, 42):\n");
	ft_printf("- ft_printf:%5d\n", 42);
	printf("-    printf:%5d\n", 42);

	ft_printf("\n");
	ft_printf("# 0128 ft_printf(05d, 42):\n");
	ft_printf("- ft_printf:%05d\n", 42);
	printf("-    printf:%05d\n", 42);

	ft_printf("\n");
	ft_printf("# 0129 ft_printf(0+5d, 42):\n");
	ft_printf("- ft_printf:%0+5d\n", 42);
	printf("-    printf:%0+5d\n", 42);

	ft_printf("\n");
	ft_printf("# 0130 ft_printf(5d, -42):\n");
	ft_printf("- ft_printf:%5d\n", -42);
	printf("-    printf:%5d\n", -42);

	ft_printf("\n");
	ft_printf("# 0131 ft_printf(05d, -42):\n");
	ft_printf("- ft_printf:%05d\n", -42);
	printf("-    printf:%05d\n", -42);

	ft_printf("\n");
	ft_printf("# 0132 ft_printf(0+5d, -42):\n");
	ft_printf("- ft_printf:%0+5d\n", -42);
	printf("-    printf:%0+5d\n", -42);

	ft_printf("\n");
	ft_printf("# 0151 ft_printf(jd, 9223372036854775807):\n");
	ft_printf("- ft_printf:%jd\n", 9223372036854775807);
	printf("-    printf:%jd\n", 9223372036854775807);

	ft_printf("\n");
	ft_printf("# 0152 ft_printf(jd, -9223372036854775808):\n");
	ft_printf("- ft_printf:%jd\n", -9223372036854775808);
	printf("-    printf:%jd\n", -9223372036854775808);

	ft_printf("\n");
	ft_printf("# 0153 ft_printf(zd, 4294967295):\n");
	ft_printf("- ft_printf:%zd\n", 4294967295);
	printf("-    printf:%zd\n", 4294967295);

	ft_printf("\n");
	ft_printf("# 0154 ft_printf(zd, 4294967296):\n");
	ft_printf("- ft_printf:%zd\n", 4294967296);
	printf("-    printf:%zd\n", 4294967296);

	ft_printf("\n");
	ft_printf("# 0165 ft_printf(10.5d, 4242):\n");
	ft_printf("- ft_printf:%10.5d\n", 4242);
	printf("-    printf:%10.5d\n", 4242);

	ft_printf("\n");
	ft_printf("# 0167 ft_printf( 10.5d, 4242):\n");
	ft_printf("- ft_printf:% 10.5d\n", 4242);
	printf("-    printf:% 10.5d\n", 4242);

	ft_printf("\n");
	ft_printf("# 0168 ft_printf(+10.5d, 4242):\n");
	ft_printf("- ft_printf:%+10.5d\n", 4242);
	printf("-    printf:%+10.5d\n", 4242);

	ft_printf("\n");
	ft_printf("# 0170 ft_printf(03.2d, 0):\n");
	ft_printf("- ft_printf:%03.2d\n", 0);
	printf("-    printf:%03.2d\n", 0);

	ft_printf("\n");
	ft_printf("# 0171 ft_printf(03.2d, 1):\n");
	ft_printf("- ft_printf:%03.2d\n", 1);
	printf("-    printf:%03.2d\n", 1);

	ft_printf("\n");
	ft_printf("# 0176 ft_printf(5.d 5.0d, 0, 0):\n");
	ft_printf("- ft_printf:%5.d %5.0d\n", 0, 0);
	printf("-    printf:%5.d %5.0d\n", 0, 0);

	ft_printf("\n");
	ft_printf("# 0177 ft_printf(u, 0):\n");
	ft_printf("- ft_printf:%u\n", 0);
	printf("-    printf:%u\n", 0);

	ft_printf("\n");
	ft_printf("# 0181 ft_printf(u, 4294967296):\n");
	ft_printf("- ft_printf:%ud\n", 4294967296);
	printf("-    printf:%ud\n", 4294967296);

	ft_printf("\n");
	ft_printf("# 0192 ft_printf(ju, 4999999999):\n");
	ft_printf("- ft_printf:%jud\n", 4999999999);
	printf("-    printf:%jud\n", 4999999999);

	ft_printf("\n");
	ft_printf("# 0193 ft_printf(ju, 4294967296):\n");
	ft_printf("- ft_printf:%jud\n", 4294967296);
	printf("-    printf:%jud\n", 4294967296);
	return (0);
}
