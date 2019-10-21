/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:32 by alagache          #+#    #+#             */
/*   Updated: 2019/04/27 19:03:34 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	needle_len;

	needle_len = (int)ft_strlen(needle);
	i = 0;
	if (haystack != NULL)
	{
		if (!needle_len)
			return ((char *)haystack);
		while (*(haystack + i))
		{
			j = 0;
			while (*(needle + j) == *(haystack + i + j))
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
