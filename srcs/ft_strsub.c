/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:34:34 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:32:33 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a string, a uint, and a size_t
** allocate a string of size len
** and fills from s + start up to len
** return a pointer to the substr
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(sstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*(sstr + len) = '\0';
	while ((int)len > i)
		*(sstr + i++) = *(s + start++);
	return (sstr);
}
