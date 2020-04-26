/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:51:37 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:16:34 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a string, and a pointer to function
** allocate a string and fills it with the result ofthe function for each char
** in the original string
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	if (!(nstr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = -1;
	while (++j < i)
		nstr[j] = f(s[j]);
	nstr[j] = '\0';
	return (nstr);
}
