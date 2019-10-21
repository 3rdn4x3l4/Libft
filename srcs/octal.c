/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:17:32 by alagache          #+#    #+#             */
/*   Updated: 2019/08/08 13:08:49 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	zero_zero_octal(t_conv_id *s_ptr, int len)
{
	int	pos;

	str_fill_char(s_ptr->output, ' ', len);
	pos = ((s_ptr->flags & 4) == 4 ? 0 : len - 1);
	if ((s_ptr->flags & 1) == 1)
		s_ptr->output[pos] = '0';
}

void	zero_no_prec_octal(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int	len_nb;

	str_fill_char(s_ptr->output, '0', len);
	pos = len - 1;
	len_nb = unsigned_len_base(nb, 8);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = '0' + nb % 8;
		nb /= 8;
		pos--;
	}
}

void	minus_octal(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int	len_nb;

	pos = 0;
	if ((s_ptr->flags & 1) == 1 && nb != 0)
	{
		s_ptr->output[pos] = '0';
		s_ptr->precision--;
		pos++;
	}
	str_fill_char(s_ptr->output + pos, ' ', len + pos);
	len_nb = unsigned_len_base(nb, 8);
	while (s_ptr->precision - len_nb > 0)
	{
		s_ptr->output[pos] = '0';
		pos++;
		s_ptr->precision--;
	}
	while (len_nb-- > 0)
	{
		s_ptr->output[pos + len_nb] = '0' + (nb % 8);
		nb /= 8;
	}
}

void	no_flag_octal(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int	len_nb;
	int	zero;

	str_fill_char(s_ptr->output, ' ', len);
	zero = (((s_ptr->flags & 1) == 1) && nb != 0 ? 1 : 0);
	pos = len - 1;
	len_nb = unsigned_len_base(nb, 8);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = '0' + (nb % 8);
		nb /= 8;
		pos--;
	}
	if (zero == 1)
		s_ptr->output[pos] = '0';
	while (pos >= len - s_ptr->precision)
	{
		s_ptr->output[pos] = '0';
		pos--;
	}
}

int		ft_conv_octal(t_conv_id *s_ptr, va_list *arg_ptr)
{
	unsigned long long	value;
	int					len;

	if (check_octal_struct(s_ptr) == -1)
		return (-1);
	get_unsigned_value(&value, arg_ptr, s_ptr);
	len = calc_len_octal(s_ptr, value);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if (value == 0 && s_ptr->precision == 0)
		zero_zero_octal(s_ptr, len);
	else if ((s_ptr->flags & 4) == 4)
		minus_octal(s_ptr, len, value);
	else if ((s_ptr->flags & 2) == 2 && s_ptr->precision == -1)
		zero_no_prec_octal(s_ptr, len, value);
	else
		no_flag_octal(s_ptr, len, value);
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
