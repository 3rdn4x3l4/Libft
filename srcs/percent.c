/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:31:03 by alagache          #+#    #+#             */
/*   Updated: 2019/10/24 16:42:10 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	minus_flag_percent(t_conv_id *s_ptr, int len)
{
	str_fill_char(s_ptr->output, ' ', len);
	s_ptr->output[0] = '%';
}

void	no_flag_percent(t_conv_id *s_ptr, int len)
{
	str_fill_char(s_ptr->output, ' ', len);
	s_ptr->output[len - 1] = '%';
}

int		calc_len_percent(t_conv_id *s_ptr)
{
	int len;

	len = (1 < s_ptr->width ? s_ptr->width : 1);
	return (len);
}

int		ft_conv_percent(t_conv_id *s_ptr, va_list *arg_ptr)
{
	int	len;

	len = calc_len_percent(s_ptr);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if ((s_ptr->flags & 4) == 4)
		minus_flag_percent(s_ptr, len);
	else
		no_flag_percent(s_ptr, len);
	write(s_ptr->fd, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
	len = va_arg(*arg_ptr, int);
}
