/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:43:44 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:07:55 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a string
** copy its content to the newly alloced string
** return a pointer to the new string
*/

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[len] = '\0';
	len = -1;
	while (s1[++len])
		dst[len] = s1[len];
	return (dst);
}
