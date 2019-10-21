/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:30:36 by alagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:38:10 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	add_strings(char *dst, char *src, int len)
{
	int	pos;
	int	carry;
	int	sum;

	pos = len - 1;
	carry = 0;
	while (pos != 0)
	{
		sum = (dst[pos] + src[pos] + carry - 96);
		dst[pos] = sum % 10 + '0';
		carry = (sum > 9 ? 1 : 0);
		pos--;
	}
}

void	multiply_str_by_two(char *str, int len)
{
	int	pos;
	int	carry;
	int	prod;

	pos = len - 1;
	carry = 0;
	while (pos != 0)
	{
		prod = (str[pos] - 48) * 2 + carry;
		str[pos] = prod % 10 + '0';
		carry = (prod > 9 ? prod / 10 : 0);
		pos--;
	}
}

void	divide_str_by_two(char *str, int len)
{
	int	pos;
	int remainder;

	pos = 0;
	remainder = 0;
	while (pos < len)
	{
		if ((str[pos] - 48) % 2 == 0)
		{
			str[pos] = (str[pos] - 48) / 2 + remainder + '0';
			remainder = 0;
		}
		else
		{
			str[pos] = (str[pos] - 48) / 2 + remainder + '0';
			remainder = 5;
		}
		pos++;
	}
}

void	apply_d_rounding(t_d_arrs *a_ptr, int prec)
{
	ft_memset(a_ptr->tmp, '0', sizeof(a_ptr->tmp));
	a_ptr->tmp[349 + prec] = '1';
	add_strings(a_ptr->tab, a_ptr->tmp, sizeof(a_ptr->tab));
}

void	apply_ld_rounding(t_ld_arrs *a_ptr, int prec)
{
	ft_memset(a_ptr->tmp, '0', sizeof(a_ptr->tmp));
	a_ptr->tmp[4999 + prec] = '1';
	add_strings(a_ptr->tab, a_ptr->tmp, sizeof(a_ptr->tab));
}
