/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:45:22 by alagache          #+#    #+#             */
/*   Updated: 2019/10/24 16:52:26 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		sign;
	long	n;
	char	*str;

	sign = (value < 0 && base == 10) ? -1 : 0;
	n = (value >= 0) ? value : -(long)value;
	i = (sign == -1) ? 2 : 1;
	while (1 <= (n /= base))
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	n = (value >= 0) ? value : -(long)value;
	while (i-- + sign)
	{
		str[i] = (n % base >= 10) ? n % base + 55 : n % base + 48;
		n /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}
