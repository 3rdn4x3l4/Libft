/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:28 by alagache          #+#    #+#             */
/*   Updated: 2019/08/08 15:09:59 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

int	calc_len_hexa(t_conv_id *s_ptr, unsigned long long value)
{
	int	len;
	int	flag;

	flag = 0;
	len = (value == 0 && s_ptr->precision == 0 ? 0 : 1);
	while (value >= 16)
	{
		value /= 16;
		len++;
	}
	if ((value != 0) && (s_ptr->flags & 1) == 1)
		flag = 2;
	len = (s_ptr->precision > len ? s_ptr->precision : len);
	len = (s_ptr->width > len + flag ? s_ptr->width : len + flag);
	return (len);
}
