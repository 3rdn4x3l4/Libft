/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:40 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:34:11 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_need_trim(char const *s, int len)
{
	int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (i == len)
		return (0);
	else
		return (1);
}

/*
** takes a string
** and trim the string of whitespace at the begining and the end
** the new string is allocated and returned
*/

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	endlen;
	size_t	start;
	char	*blank;

	if (!s)
		return ((char *)s);
	len = ft_strlen(s);
	endlen = len - 1;
	start = 0;
	if (ft_need_trim(s, (int)len) == 0)
		return (ft_strnew(0));
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (s[endlen] == ' ' || s[endlen] == '\t' || s[endlen] == '\n')
		endlen--;
	len = endlen - start + 1;
	blank = ft_strsub(s, start, len);
	return (blank);
}
