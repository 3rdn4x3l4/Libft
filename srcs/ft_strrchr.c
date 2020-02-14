/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:19 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:26:56 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a string and a char
** return a pointer to the last occurence of the char in the string or NULL
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s != NULL)
	{
		i = ft_strlen(s) + 1;
		while (i--)
		{
			if (*(s + i) == (char)c)
				return ((char *)s + i);
		}
	}
	return (NULL);
}
