/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:39:25 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:58:02 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(const size_t size)
{
	unsigned char	*mz;

	if (!(mz = (unsigned char*)malloc(sizeof(int) * size)))
		return (NULL);
	ft_memset(mz, 0, size);
	return (mz);
}
