/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:41:21 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:24:55 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a string
** allocate a new string of the same size of the original and fills it with '\0'
*/

char	*ft_strnew(size_t size)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(dst, '\0', size + 1);
	return (dst);
}
