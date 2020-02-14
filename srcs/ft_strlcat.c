/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:08 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:14:50 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes two strings
** append the string src to dst making sure dst is at most size char long
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (dst[i] && i < size)
		i++;
	while (src[++j] && i + j + 1 < size)
		dst[i + j] = src[j];
	if (i != size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
