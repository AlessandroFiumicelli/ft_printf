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
	ft_printf("ft_printf(d, 0)\n");
	ft_printf("- ft_printf:%d\n", 0);
	printf("-    printf:%d\n", 0);

	ft_printf("\n");
	ft_printf("ft_printf(X, 0):\n");
	ft_printf("- ft_printf:%X\n", 0);
	printf("-    printf:%X\n", 0);

	ft_printf("\n");
	ft_printf("ft_printf(x, 4294967296):\n");
	ft_printf("- ft_printf:%x\n", 4294967296);
	printf("-    printf:%x\n", 4294967296);

	ft_printf("\n");
	ft_printf("ft_printf(X, 4294967296):\n");
	ft_printf("- ft_printf:%X\n", 4294967296);
	printf("-    printf:%X\n", 4294967296);

	ft_printf("\n");
	ft_printf("ft_printf(hx, 4294967296):\n");
	ft_printf("- ft_printf:%hx\n", 4294967296);
	printf("-    printf:%x\n", 4294967296);

	ft_printf("\n");
	ft_printf("ft_printf(hhX, 4294967296):\n");
	ft_printf("- ft_printf:%hhX\n", 4294967296);
	printf("-    printf:%hhX\n", 4294967296);

	ft_printf("\n");
	ft_printf("ft_printf(jx, 4294967296):\n");
	ft_printf("- ft_printf:%jx\n", 4294967296);
	printf("-    printf:%jx\n", 4294967296);

	ft_printf("\n");
	ft_printf("ft_printf(#x, 0):\n");
	ft_printf("- ft_printf:%#x\n", 0);
	printf("-    printf:%#x\n", 0);

	ft_printf("\n");
	ft_printf("ft_printf(#.d #.0d, 0, 0):\n");
	ft_printf("- ft_printf:%#.d %#.0d\n", 0, 0);
	printf("-    printf:%#.d %#.0d\n", 0);
	
	ft_printf("\n");
	ft_printf("ft_printf(5.x 5.0x, 0, 0):\n");
	ft_printf("- ft_printf:%5.x %5.0x\n", 0, 0);
	printf("-    printf:%5.x %5.0x\n", 0, 0);
	
	ft_printf("\n");
	ft_printf("ft_printf(o, 0):\n");
	ft_printf("- ft_printf:%o\n", 0);
	printf("-    printf:%o\n", 0);
	
	ft_printf("\n");
	ft_printf("ft_printf(5d, 42):\n");
	ft_printf("- ft_printf:%5d\n", 42);
	printf("-    printf:%5d\n", 42);
	return (0);
}
