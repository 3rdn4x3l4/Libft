/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:30:59 by alagache          #+#    #+#             */
/*   Updated: 2019/08/07 16:35:07 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	get_address_value(unsigned long *val_ptr, va_list *arg_ptr)
{
	*val_ptr = (unsigned long)va_arg(*arg_ptr, void *);
}

int		calc_len_address(t_conv_id *s_ptr, unsigned long value)
{
	int	len;

	len = unsigned_len_base(value, 16);
	len = (s_ptr->width > len + 2 ? s_ptr->width : len + 2);
	return (len);
}
