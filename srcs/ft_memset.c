/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:39:45 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 19:04:34 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a mz, an int and a size
** set size bytes of the mz as the value of the int
*/

void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = -1;
	if (b == NULL)
		return (NULL);
	while (++i < (int)len)
		((unsigned char *)b)[i] = (unsigned char)c;
	return (b);
}
