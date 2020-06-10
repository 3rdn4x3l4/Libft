/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:54:04 by alagache          #+#    #+#             */
/*   Updated: 2020/06/10 17:00:37 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *str)
{
	int			iterator;
	long long	stock;
	int			sign;

	sign = 1;
	stock = 0;
	iterator = 0;
	while (str[iterator] == 32 || str[iterator] == '\n' || str[iterator] == '\t'
			|| str[iterator] == '\v' || str[iterator] == '\f'
			|| str[iterator] == '\r')
		iterator++;
	if (str[iterator] == '-')
		sign = -1;
	if (str[iterator] == '+' || str[iterator] == '-')
		iterator++;
	while (str[iterator] <= 57 && str[iterator] >= 48)
	{
		stock = str[iterator] - '0' + (10 * stock);
		iterator++;
	}
	return (stock * sign);
}
