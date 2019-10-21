/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:00:02 by alagache          #+#    #+#             */
/*   Updated: 2019/08/08 14:01:35 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	zero_zero_int(t_conv_id *s_ptr, int len)
{
	int	pos;

	str_fill_char(s_ptr->output, ' ', len);
	pos = ((s_ptr->flags & 4) == 4 ? 0 : len - 1);
	if ((s_ptr->flags & 16) == 16)
		s_ptr->output[pos] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[pos] = ' ';
}

void	minus_int(t_conv_id *s_ptr, int len, long long int nb)
{
	int	pos;
	int	len_nb;

	pos = 0;
	if (nb < 0)
		s_ptr->output[pos++] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[pos++] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[pos++] = ' ';
	str_fill_char(s_ptr->output + pos, ' ', len - pos);
	len_nb = int_len(nb);
	while (s_ptr->precision - len_nb > 0)
	{
		s_ptr->output[pos] = '0';
		pos++;
		s_ptr->precision--;
	}
	while (len_nb-- > 0)
	{
		s_ptr->output[pos + len_nb] = '0' +
			(nb % 10 < 0 ? -(nb % 10) : nb % 10);
		nb /= 10;
	}
}

void	zero_no_prec_int(t_conv_id *s_ptr, int len, long long int nb)
{
	int	pos;
	int	len_nb;

	str_fill_char(s_ptr->output, '0', len);
	if (nb < 0)
		s_ptr->output[0] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[0] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[0] = ' ';
	pos = len - 1;
	len_nb = int_len(nb);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = '0' + (nb % 10 < 0 ? -(nb % 10) : nb % 10);
		nb /= 10;
		pos--;
	}
}

void	no_flag_int(t_conv_id *s_ptr, int len, long long int nb)
{
	int	pos;
	int	s;
	int	len_nb;

	str_fill_char(s_ptr->output, ' ', len);
	pos = len - 1;
	s = (nb < 0 ? 1 : 0);
	len_nb = int_len(nb);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = '0' + (nb % 10 < 0 ? -(nb % 10) : nb % 10);
		pos--;
		nb /= 10;
	}
	while (pos >= len - s_ptr->precision)
	{
		s_ptr->output[pos] = '0';
		pos--;
	}
	if (s == 1)
		s_ptr->output[pos] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[pos] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[pos] = ' ';
}

int		ft_conv_int(t_conv_id *s_ptr, va_list *arg_ptr)
{
	long long int	value;
	int				len;

	if (check_int_struct(s_ptr) == -1)
		return (-1);
	get_int_value(&value, arg_ptr, s_ptr);
	len = calc_len_int(s_ptr, value);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if (value == 0 && s_ptr->precision == 0)
		zero_zero_int(s_ptr, len);
	else if ((s_ptr->flags & 4) == 4)
		minus_int(s_ptr, len, value);
	else if ((s_ptr->flags & 2) == 2 && s_ptr->precision == -1)
		zero_no_prec_int(s_ptr, len, value);
	else
		no_flag_int(s_ptr, len, value);
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
