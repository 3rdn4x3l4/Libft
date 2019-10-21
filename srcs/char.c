/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:06 by alagache          #+#    #+#             */
/*   Updated: 2019/08/02 11:31:08 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

int	ft_conv_char(t_conv_id *s_ptr, va_list *arg_ptr)
{
	int		len;
	int		pos;
	char	value;

	value = (char)va_arg(*arg_ptr, int);
	len = (1 < s_ptr->width ? s_ptr->width : 1);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s_ptr->output[len] = '\0';
	str_fill_char(s_ptr->output, ' ', len);
	pos = ((s_ptr->flags & 4) == 4 ? 0 : len - 1);
	s_ptr->output[pos] = value;
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
