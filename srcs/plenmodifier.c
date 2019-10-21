/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plenmodifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:41:23 by plagache          #+#    #+#             */
/*   Updated: 2019/08/02 11:31:53 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg.h"
#include "libft.h"

int	len_modifier_in_struct(char *ptr, int len, t_conv_id *struct_ptr)
{
	if (len == 0)
	{
		struct_ptr->len_modif1 = ptr[len];
		return (len);
	}
	if (len > 0)
	{
		struct_ptr->len_modif2 = ptr[len];
		return (len);
	}
	return (0);
}

int	len_modifier(char *ptr, int end, t_conv_id *struct_ptr)
{
	int len;

	len = 0;
	while (len < end)
	{
		if (ft_strchr("hlL", ptr[len]) != NULL)
			len_modifier_in_struct(ptr, len, struct_ptr);
		else
			return (len);
		len++;
	}
	return (len);
}
