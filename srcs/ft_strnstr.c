/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:26 by alagache          #+#    #+#             */
/*   Updated: 2019/04/27 19:05:27 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	needle_len;

	i = 0;
	needle_len = (int)ft_strlen(needle);
	if (haystack != NULL)
	{
		if (!needle_len)
			return ((char *)haystack);
		while (*(haystack + i) && i < (int)len)
		{
			j = 0;
			while (*(needle + j) == *(haystack + i + j) && i + j < (int)len)
			{
				j++;
				if (j == needle_len)
					return ((char *)haystack + i);
			}
			i++;
		}
	}
	return (NULL);
}
