/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:24:51 by alfiumic          #+#    #+#             */
/*   Updated: 2019/02/20 15:47:19 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && i < maxlen)
		i++;
	return (i);
}
