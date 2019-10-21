/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:23:52 by alagache          #+#    #+#             */
/*   Updated: 2019/08/02 11:31:24 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

int	str_fill_char(char *str, char c, int len)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (0);
}

int	unsigned_len_base(unsigned long long val, unsigned base)
{
	int	len;

	len = 1;
	while (val >= base)
	{
		val /= base;
		len++;
	}
	return (len);
}
