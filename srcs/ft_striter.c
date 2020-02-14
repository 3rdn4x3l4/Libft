/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:14:26 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:09:05 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a string and a pointer to function
** apply the function to every char in the string
*/

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	i = -1;
	if (s != NULL && f != NULL)
	{
		while (s[++i])
			f(s + i);
	}
}
