/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:30:14 by alagache          #+#    #+#             */
/*   Updated: 2019/07/24 11:44:48 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*min_int(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	ft_strcpy(str, "-2147483648");
	return (str);
}

static char	*neg_ints(int n)
{
	char	*str;
	int		cpy;
	int		chrs;

	cpy = n;
	chrs = 2;
	while (cpy > 9)
	{
		cpy /= 10;
		chrs++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (chrs + 1))))
		return (NULL);
	str[chrs] = '\0';
	str[0] = '-';
	while (--chrs > 0)
	{
		str[chrs] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static char	*pos_ints(int n)
{
	char	*str;
	int		cpy;
	int		chrs;

	cpy = n;
	chrs = 1;
	while (cpy > 9)
	{
		cpy /= 10;
		chrs++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (chrs + 1))))
		return (NULL);
	str[chrs] = '\0';
	while (--chrs >= 0)
	{
		str[chrs] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = min_int();
		return (str);
	}
	if (n < 0)
	{
		if ((str = neg_ints(-n)) == NULL)
			return (NULL);
		return (str);
	}
	if (n >= 0)
	{
		if ((str = pos_ints(n)) == NULL)
			return (NULL);
		return (str);
	}
	return (NULL);
}
