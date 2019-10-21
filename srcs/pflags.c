/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:20:09 by plagache          #+#    #+#             */
/*   Updated: 2019/08/02 11:31:51 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg.h"
#include "libft.h"

void	flags_in_struct(char c, t_conv_id *struct_ptr)
{
	if (c == '#' && (struct_ptr->flags & 1) == 0)
		struct_ptr->flags ^= 1;
	if (c == '0' && (struct_ptr->flags & 2) == 0)
		struct_ptr->flags ^= 2;
	if (c == '-' && (struct_ptr->flags & 4) == 0)
		struct_ptr->flags ^= 4;
	if (c == ' ' && (struct_ptr->flags & 8) == 0)
		struct_ptr->flags ^= 8;
	if (c == '+' && (struct_ptr->flags & 16) == 0)
		struct_ptr->flags ^= 16;
}

int		flag(char *ptr, int end, t_conv_id *struct_ptr)
{
	int pos;

	pos = 1;
	struct_ptr->flags = 0;
	while (ft_strchr("#0- +", ptr[pos]) != NULL)
	{
		flags_in_struct(ptr[pos], struct_ptr);
		pos++;
	}
	if ((pos - end) > 0)
		return (-1);
	return (pos);
}
