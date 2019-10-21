/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:11:15 by plagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:43:22 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"
#include <stdio.h>

void	special_value(t_s_e_m *dble_ptr, t_conv_id *s_ptr, int len)
{
	if (dble_ptr->s == 1)
	{
		s_ptr->output[(len - ft_strlen(dble_ptr->str) - 1)] = '-';
		ft_memcpy((s_ptr->output + (len - ft_strlen(dble_ptr->str))),
				dble_ptr->str, ft_strlen(dble_ptr->str));
	}
	else if ((s_ptr->flags & 16) == 16 && ft_strcmp(dble_ptr->str, "nan") != 0)
	{
		s_ptr->output[(len - ft_strlen(dble_ptr->str) - 1)] = '+';
		ft_memcpy((s_ptr->output + (len - ft_strlen(dble_ptr->str))),
				dble_ptr->str, ft_strlen(dble_ptr->str));
	}
	else if ((s_ptr->flags & 8) == 8 && ft_strcmp(dble_ptr->str, "nan") != 0)
	{
		s_ptr->output[(len - ft_strlen(dble_ptr->str) - 1)] = ' ';
		ft_memcpy((s_ptr->output + (len - ft_strlen(dble_ptr->str))),
				dble_ptr->str, ft_strlen(dble_ptr->str));
	}
	else
	{
		ft_memcpy((s_ptr->output + (len - ft_strlen(dble_ptr->str))),
				dble_ptr->str, ft_strlen(dble_ptr->str));
	}
}

void	minus_special_value(t_s_e_m *dble_ptr, t_conv_id *s_ptr)
{
	if (dble_ptr->s == 1)
	{
		s_ptr->output[0] = '-';
		ft_memcpy(s_ptr->output + 1, dble_ptr->str, ft_strlen(dble_ptr->str));
	}
	else if ((s_ptr->flags & 16) == 16 && ft_strcmp(dble_ptr->str, "nan") != 0)
	{
		s_ptr->output[0] = '+';
		ft_memcpy(s_ptr->output + 1, dble_ptr->str, ft_strlen(dble_ptr->str));
	}
	else if ((s_ptr->flags & 8) == 8 && ft_strcmp(dble_ptr->str, "nan") != 0)
	{
		s_ptr->output[0] = ' ';
		ft_memcpy(s_ptr->output + 1, dble_ptr->str, ft_strlen(dble_ptr->str));
	}
	else
		ft_memcpy(s_ptr->output, dble_ptr->str, ft_strlen(dble_ptr->str));
}
