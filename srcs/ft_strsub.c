/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:34:34 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:59:57 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
