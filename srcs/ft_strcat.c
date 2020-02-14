/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:18:59 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 17:54:12 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes two strings
** add s2 content to to s1 content
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		i++;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
