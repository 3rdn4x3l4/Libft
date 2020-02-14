/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:09:03 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:55:10 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes two memory zone, a char and an size
** copy the content of src to dst
** stop the copy if the char was copied and return a pointer after it
** otherwise return NULL
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (i < ((int)n))
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char *)dst)[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
