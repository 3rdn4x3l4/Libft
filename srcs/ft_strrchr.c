/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:19 by alagache          #+#    #+#             */
/*   Updated: 2019/04/27 19:51:17 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
