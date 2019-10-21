/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:27:36 by plagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:47:43 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"
#include <stdio.h>

int		longd_special_value(t_s_e_m *dble_ptr)
{
	dble_ptr->str = NULL;
	if (((dble_ptr->e & 0x7fffULL) == 0x7fffULL) && dble_ptr->m == 0)
		dble_ptr->str = "inf";
	if (((dble_ptr->e & 0x7fffULL) == 0x7fffULL) && (dble_ptr->m >> 63) == 1)
		dble_ptr->str = "inf";
	else if (((dble_ptr->e & 0x7fffULL) == 0x7fffULL) && dble_ptr->m != 0)
		dble_ptr->str = "nan";
	if (dble_ptr->str != NULL)
		return (1);
	return (0);
}

int		ft_longd_special(t_conv_id *s_ptr, t_s_e_m *dble)
{
	int len;

	if (longd_special_value(dble) == 1)
	{
		len = ((s_ptr->width > (int)ft_strlen(dble->str)) ? s_ptr->width :
			(int)ft_strlen(dble->str));
		if ((((s_ptr->flags & 24) != 0 && len == (int)ft_strlen(dble->str))
			|| (s_ptr->width <= 3 && dble->s == 1))
				&& ft_strcmp(dble->str, "nan") != 0)
			len++;
		if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
			return (-1);
		s_ptr->output[len] = '\0';
		str_fill_char(s_ptr->output, ' ', len);
		if (((s_ptr->flags) & 4) != 0)
			minus_special_value(dble, s_ptr);
		else
			special_value(dble, s_ptr, len);
		write(1, s_ptr->output, len);
		free(s_ptr->output);
		return (len);
	}
	return (-2);
}

int		check_special_value(t_s_e_m *dble_ptr)
{
	if ((((dble_ptr->e) & 0x7ffULL) == 0x7ffULL) && dble_ptr->m == 0)
		dble_ptr->str = "inf";
	if ((((dble_ptr->e) & 0x7ffULL) == 0x7ffULL) && ((dble_ptr->m) != 0))
		dble_ptr->str = "nan";
	if (dble_ptr->str != NULL)
		return (1);
	return (0);
}

int		ft_double_special(t_conv_id *s_ptr, t_s_e_m *dble)
{
	int len;

	if (check_special_value(dble) == 1)
	{
		len = ((s_ptr->width > (int)ft_strlen(dble->str)) ? s_ptr->width :
			(int)ft_strlen(dble->str));
		if ((((s_ptr->flags & 24) != 0 && len == (int)ft_strlen(dble->str))
			|| (s_ptr->width <= 3 && dble->s == 1))
				&& ft_strcmp(dble->str, "nan") != 0)
			len++;
		if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
			return (-1);
		s_ptr->output[len] = '\0';
		str_fill_char(s_ptr->output, ' ', len);
		if (((s_ptr->flags) & 4) != 0)
			minus_special_value(dble, s_ptr);
		else
			special_value(dble, s_ptr, len);
		write(1, s_ptr->output, len);
		free(s_ptr->output);
		return (len);
	}
	return (-2);
}
