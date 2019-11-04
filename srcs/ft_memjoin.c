/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:21:23 by alagache          #+#    #+#             */
/*   Updated: 2019/11/04 17:47:59 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memjoin(void *s1, size_t n1, void *s2, size_t n2)
{
	void	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_memalloc(n1 + n2);
	ft_memcpy(s, s1, n1);
	ft_memcpy(s + n1, s2, n2);
	printf("|%s|\n", (char*)s);
	return (s);
}
