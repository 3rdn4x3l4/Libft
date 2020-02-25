/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:03:52 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:28:30 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	w_count;
	int	pos;

	w_count = 0;
	pos = 0;
	while (s[pos])
	{
		while (s[pos] == c)
			pos++;
		if (s[pos] != c && s[pos] != '\0')
			w_count++;
		while (s[pos] != c && s[pos] != '\0')
			pos++;
	}
	return (w_count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;
	int	p;

	p = 0;
	len = 0;
	while (s[p] == c)
		p++;
	while (s[p] != c && s[p] != '\0')
	{
		len++;
		p++;
	}
	return (len);
}

/*
** takes a string and a char
** make the string an array of strings cutting out char
*/

char		**ft_strsplit(char const *s, char c)
{
	char	**w_arr;
	int		w_index;
	int		l;
	int		p;

	p = 0;
	w_index = -1;
	if (!s || !(w_arr = (char**)malloc(sizeof(char *) *
	(ft_count_words(s, c) + 1))))
		return (NULL);
	while (++w_index < ft_count_words(s, c))
	{
		l = 0;
		if (!(w_arr[w_index] = ft_strnew(ft_wordlen(&s[p], c))))
			w_arr[w_index] = NULL;
		while (s[p] == c)
			p++;
		while (s[p] != c && s[p] != '\0' && w_arr[w_index] != NULL)
			w_arr[w_index][l++] = s[p++];
	}
	w_arr[w_index] = 0;
	return (w_arr);
}
