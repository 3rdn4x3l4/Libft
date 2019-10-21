/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:17:37 by alagache          #+#    #+#             */
/*   Updated: 2019/08/08 12:46:46 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

int	check_octal_struct(t_conv_id *s_ptr)
{
	if ((s_ptr->flags & 24) != 0)
		return (0);
	if ((s_ptr->flags & 6) == 6)
		return (0);
	if (s_ptr->len_modif1 == 'L' || s_ptr->len_modif2 == 'L')
		return (0);
	if (s_ptr->len_modif1 != 0 && s_ptr->len_modif2 != 0)
	{
		if (s_ptr->len_modif1 != s_ptr->len_modif2)
			return (0);
	}
	return (0);
}

int	calc_len_octal(t_conv_id *s_ptr, unsigned long long value)
{
	int	len;
	int	flag;

	flag = 0;
	len = (value == 0 && s_ptr->precision == 0 ? 0 : 1);
	while (value >= 8)
	{
		value /= 8;
		len++;
	}
	if ((s_ptr->precision != -1 || value != 0) && s_ptr->precision <= len
		&& (s_ptr->flags & 1) == 1)
		flag = 1;
	len = (s_ptr->precision > len ? s_ptr->precision : len);
	len = (s_ptr->width > len + flag ? s_ptr->width : len + flag);
	return (len);
}
