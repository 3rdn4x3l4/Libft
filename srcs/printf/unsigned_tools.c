/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:00:04 by plagache          #+#    #+#             */
/*   Updated: 2019/08/07 12:52:34 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

int		check_unsigned_struct(t_conv_id *ptr)
{
	if ((ptr->flags & 25) != 0)
		return (0);
	if ((ptr->flags & 6) == 6)
		return (0);
	if (ptr->len_modif1 == 'L' || ptr->len_modif2 == 'L')
		return (0);
	if (ptr->len_modif1 != 0 && ptr->len_modif2 != 0)
	{
		if (ptr->len_modif1 != ptr->len_modif2)
			return (0);
	}
	return (0);
}

void	get_unsigned_value(unsigned long long *val_ptr, va_list *arg_ptr,
		t_conv_id *s_ptr)
{
	if (s_ptr->len_modif1 == 'l' && s_ptr->len_modif2 == 0)
		*val_ptr = (unsigned long)va_arg(*arg_ptr, unsigned long);
	else if (s_ptr->len_modif1 == 'l' && s_ptr->len_modif2 == 'l')
		*val_ptr = (unsigned long long)va_arg(*arg_ptr, unsigned long long);
	else if (s_ptr->len_modif1 == 'h' && s_ptr->len_modif2 == 0)
		*val_ptr = (unsigned short)va_arg(*arg_ptr, unsigned int);
	else if (s_ptr->len_modif1 == 'h' && s_ptr->len_modif2 == 'h')
		*val_ptr = (unsigned char)va_arg(*arg_ptr, unsigned int);
	else if (s_ptr->len_modif1 == 0 && s_ptr->len_modif2 == 0)
		*val_ptr = va_arg(*arg_ptr, unsigned int);
}

int		calc_len_unsigned(t_conv_id *s_ptr, unsigned long long value)
{
	int	len;

	len = (value == 0 && s_ptr->precision == 0 ? 0 : 1);
	while (value > 9)
	{
		value /= 10;
		len++;
	}
	len = (s_ptr->precision > len ? s_ptr->precision : len);
	len = (s_ptr->width > len ? s_ptr->width : len);
	return (len);
}
