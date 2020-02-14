/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:21:23 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 19:00:07 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** takes two mz and their respective sizes
** allocated a mz of the size of the sum of the sizes
** and fills the new mz with mz1 followed by the mz2
*/

void	*ft_memjoin(void *s1, size_t n1, void *s2, size_t n2)
{
	void	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_memalloc(n1 + n2);
	ft_memcpy(s, s1, n1);
	ft_memcpy(s + n1, s2, n2);
	return (s);
}
