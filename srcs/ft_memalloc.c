/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:39:25 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:53:09 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a size
** allocate a memory size fills it with zeros
** and return a pointer to the zone
*/

void	*ft_memalloc(const size_t size)
{
	unsigned char	*mz;

	if (!(mz = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	ft_memset(mz, 0, size);
	return (mz);
}
