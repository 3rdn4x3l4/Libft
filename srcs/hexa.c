/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:26 by alagache          #+#    #+#             */
/*   Updated: 2019/08/08 14:42:17 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	zero_zero_hexa(t_conv_id *s_ptr, int len)
{
	str_fill_char(s_ptr->output, ' ', len);
}

void	minus_flag_hexa(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int len_nb;

	pos = 0;
	len_nb = unsigned_len_base(nb, 16);
	if ((s_ptr->flags & 1) == 1 && nb != 0)
	{
		s_ptr->output[pos++] = '0';
		s_ptr->output[pos++] = 'x';
	}
	str_fill_char(s_ptr->output + pos, ' ', len - pos);
	while (s_ptr->precision - len_nb > 0)
	{
		s_ptr->output[pos] = '0';
		pos++;
		s_ptr->precision--;
	}
	while (len_nb-- > 0)
	{
		s_ptr->output[pos + len_nb] = (nb % 16 > 9 ? 87 + nb % 16 :
		'0' + nb % 16);
		nb /= 16;
	}
}

void	zero_flag_hexa(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int	len_nb;

	pos = 0;
	str_fill_char(s_ptr->output, '0', len);
	if ((s_ptr->flags & 1) == 1 && nb != 0)
	{
		s_ptr->output[pos++] = '0';
		s_ptr->output[pos++] = 'x';
	}
	pos = len - 1;
	len_nb = unsigned_len_base(nb, 16);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = (nb % 16 > 9 ? 87 + nb % 16 :
		'0' + nb % 16);
		nb /= 16;
		pos--;
	}
}

void	no_flag_hexa(t_conv_id *s_ptr, int len, unsigned long long nb)
{
	int	pos;
	int len_nb;
	int nb_cpy;

	nb_cpy = nb;
	str_fill_char(s_ptr->output, ' ', len);
	pos = len - 1;
	len_nb = unsigned_len_base(nb, 16);
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = (nb % 16 > 9 ? 87 + nb % 16 :
		'0' + nb % 16);
		nb /= 16;
		pos--;
	}
	while (pos >= len - s_ptr->precision)
	{
		s_ptr->output[pos] = '0';
		pos--;
	}
	if ((s_ptr->flags & 1) == 1 && nb_cpy != 0)
	{
		s_ptr->output[pos--] = 'x';
		s_ptr->output[pos] = '0';
	}
}

int		ft_conv_hexa(t_conv_id *s_ptr, va_list *arg_ptr)
{
	int					len;
	unsigned long long	value;

	get_unsigned_value(&value, arg_ptr, s_ptr);
	len = calc_len_hexa(s_ptr, value);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if (value == 0 && s_ptr->precision == 0)
		zero_zero_hexa(s_ptr, len);
	else if ((s_ptr->flags & 4) == 4)
		minus_flag_hexa(s_ptr, len, value);
	else if ((s_ptr->flags & 2) == 2 && s_ptr->precision == -1)
		zero_flag_hexa(s_ptr, len, value);
	else
		no_flag_hexa(s_ptr, len, value);
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
