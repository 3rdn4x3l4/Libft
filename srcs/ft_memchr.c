/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:15:48 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:58:17 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;

	i = 0;
	if (s != NULL)
	{
		while (i < (int)n)
		{
			if (((unsigned char *)s)[i] == (unsigned char)c)
				return ((unsigned char *)s + i);
			i++;
		}
	}
	return (NULL);
}
