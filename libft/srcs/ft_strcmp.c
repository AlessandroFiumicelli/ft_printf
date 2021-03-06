/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:56:55 by alfiumic          #+#    #+#             */
/*   Updated: 2019/02/20 15:38:50 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] == s2[len])
		len++;
	return (*((unsigned char *)s1 + len) - *((unsigned char *)s2 + len));
}
