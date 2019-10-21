/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:59:53 by plagache          #+#    #+#             */
/*   Updated: 2019/08/02 11:32:06 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	zero_zero_unsigned(t_conv_id *s_ptr, int len)
{
	str_fill_char(s_ptr->output, ' ', len);
}

void	minus_flag_unsigned(t_conv_id *s_ptr, int len,
		unsigned long long nb)
{
	int pos;
	int len_nb;

	len_nb = unsigned_len_base(nb, 10);
	pos = 0;
	str_fill_char(s_ptr->output, ' ', len);
	while (s_ptr->precision - len_nb > 0)
	{
		s_ptr->output[pos] = '0';
		pos++;
		s_ptr->precision--;
	}
	while (len_nb-- > 0)
	{
		s_ptr->output[pos + len_nb] = '0' + (nb % 10);
		nb /= 10;
	}
}

void	zero_flag_unsigned(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int	len_nb;

	pos = len - 1;
	len_nb = unsigned_len_base(nb, 10);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = '0' + (nb % 10);
		nb /= 10;
		pos--;
	}
	while (pos >= 0)
	{
		s_ptr->output[pos] = '0';
		pos--;
	}
}

void	no_flag_unsigned(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int len_nb;

	pos = len - 1;
	str_fill_char(s_ptr->output, ' ', len);
	len_nb = unsigned_len_base(nb, 10);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = '0' + (nb % 10);
		nb /= 10;
		pos--;
	}
	while (pos >= len - s_ptr->precision)
	{
		s_ptr->output[pos] = '0';
		pos--;
	}
}

int		ft_conv_unsigned(t_conv_id *s_ptr, va_list *arg_ptr)
{
	unsigned long long	value;
	int					len;

	if (check_unsigned_struct(s_ptr) == -1)
		return (-1);
	get_unsigned_value(&value, arg_ptr, s_ptr);
	len = calc_len_unsigned(s_ptr, value);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if (value == 0 && s_ptr->precision == 0)
		zero_zero_unsigned(s_ptr, len);
	else if ((s_ptr->flags & 4) == 4)
		minus_flag_unsigned(s_ptr, len, value);
	else if ((s_ptr->flags & 2) == 2 && s_ptr->precision == -1)
		zero_flag_unsigned(s_ptr, len, value);
	else
		no_flag_unsigned(s_ptr, len, value);
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
