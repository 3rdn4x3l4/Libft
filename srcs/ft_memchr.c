/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:15:48 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:56:09 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a memory zone, a char, and the zone size
** return a pointer to the char in the memory zone or NULL
*/

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
