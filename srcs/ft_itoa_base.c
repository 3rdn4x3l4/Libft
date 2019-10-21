/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:45:22 by alagache          #+#    #+#             */
/*   Updated: 2019/07/24 11:45:26 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*min_int(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

int		ft_nbrlen(int value, int base)
{
	int	len;

	len = 1;
	while (value >= base)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*negative(int value)
{
	char	*str;
	int		c;

	if (value == -2147483648)
	{
		str = min_int();
		return (str);
	}
	c = ft_nbrlen(value, 10) + 1;
	if (!(str = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	str[c] = '\0';
	str[0] = '-';
	value = -value;
	while (--c > 0)
	{
		str[c] = '0' + (value % 10);
		value /= 10;
	}
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	char			*str;
	int				c;
	unsigned int	u;

	if (base == 10 && value < 0)
	{
		str = negative(value);
		return (str);
	}
	u = (unsigned int)value;
	c = ft_nbrlen(u, base);
	if (!(str = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	str[c] = '\0';
	while (--c >= 0)
	{
		str[c] = (u % base > 9 ? 'A' + ((u % base) - 10) : '0' + (u % base));
		u /= base;
	}
	return (str);
}
