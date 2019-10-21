/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwidth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:34:48 by plagache          #+#    #+#             */
/*   Updated: 2019/08/02 11:31:57 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg.h"
#include "libft.h"

void	width_in_struct(char c, t_conv_id *struct_ptr)
{
	struct_ptr->width = (struct_ptr->width * 10) + c - '0';
}

int		width(char *ptr, int end, t_conv_id *struct_ptr)
{
	int pos;

	pos = 0;
	while (ft_isdigit(ptr[pos]) == 1)
	{
		width_in_struct(ptr[pos], struct_ptr);
		pos++;
	}
	if ((pos - end) > 0)
		return (-1);
	return (pos);
}
