/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:00:12 by alagache          #+#    #+#             */
/*   Updated: 2019/08/07 12:51:55 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

int		check_int_struct(t_conv_id *ptr)
{
	if ((ptr->flags & 1) == 1)
		return (0);
	if ((ptr->flags & 6) == 6 || (ptr->flags & 24) == 24)
		return (0);
	if (ptr->len_modif1 != 0 && ptr->len_modif2 != 0)
	{
		if (ptr->len_modif1 != ptr->len_modif2)
			return (0);
	}
	if (ptr->len_modif1 == 'L' || ptr->len_modif2 == 'L')
		return (0);
	return (0);
}

void	get_int_value(long long int *val_ptr, va_list *arg_ptr,
		t_conv_id *s_ptr)
{
	if (s_ptr->len_modif1 == 'l' && s_ptr->len_modif2 == 0)
		*val_ptr = (long int)va_arg(*arg_ptr, long int);
	else if (s_ptr->len_modif1 == 'l' && s_ptr->len_modif2 == 'l')
		*val_ptr = (long long int)va_arg(*arg_ptr, long long int);
	else if (s_ptr->len_modif1 == 'h' && s_ptr->len_modif2 == 0)
		*val_ptr = (short int)va_arg(*arg_ptr, int);
	else if (s_ptr->len_modif1 == 'h' && s_ptr->len_modif2 == 'h')
		*val_ptr = (char)va_arg(*arg_ptr, int);
	else if (s_ptr->len_modif1 == 0 && s_ptr->len_modif2 == 0)
		*val_ptr = va_arg(*arg_ptr, int);
}

int		int_len(long long int val)
{
	int	len;

	len = 1;
	while (val > 9 || val < -9)
	{
		len++;
		val /= 10;
	}
	return (len);
}

int		calc_len_int(t_conv_id *s_ptr, long long int value)
{
	int	len;
	int	s;

	len = (value == 0 && s_ptr->precision == 0 ? 0 : 1);
	s = 0;
	if ((s_ptr->flags & 24) != 0 || value < 0)
		s = 1;
	while (value > 9 || value < -9)
	{
		value /= 10;
		len++;
	}
	len = (s_ptr->precision > len ? s_ptr->precision : len);
	len = (s_ptr->width > len + s ? s_ptr->width : len + s);
	return (len);
}
