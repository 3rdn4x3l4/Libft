/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:30:55 by alagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:36:16 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	minus_flag_address(t_conv_id *s_ptr, int len, unsigned long nb)
{
	int	pos;
	int len_nb;

	len_nb = unsigned_len_base(nb, 16);
	s_ptr->output[0] = '0';
	s_ptr->output[1] = 'x';
	pos = 2;
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

void	no_flag_address(t_conv_id *s_ptr, int len, unsigned long nb)
{
	int	pos;
	int	len_nb;
	int	len_cpy;

	str_fill_char(s_ptr->output, ' ', len);
	len_nb = unsigned_len_base(nb, 16);
	len_cpy = len_nb;
	pos = len - 1;
	while (len_nb-- > 0)
	{
		s_ptr->output[pos] = (nb % 16 > 9 ? 87 + nb % 16 :
		'0' + nb % 16);
		nb /= 16;
		pos--;
	}
	while (s_ptr->precision - len_cpy > 0)
	{
		s_ptr->output[pos] = '0';
		pos--;
		s_ptr->precision--;
	}
	s_ptr->output[pos--] = 'x';
	s_ptr->output[pos] = '0';
}

int		null_ptr_zero(t_conv_id *s_ptr, int len)
{
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	str_fill_char(s_ptr->output, ' ', len);
	if ((s_ptr->flags & 4) == 4)
		ft_memcpy(s_ptr->output, "0x", 2);
	else
		ft_memcpy(s_ptr->output + len - 2, "0x", 2);
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}

int		null_ptr(t_conv_id *s_ptr, int len)
{
	len = (s_ptr->precision != -1 ? len + s_ptr->precision - 1 : len);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	str_fill_char(s_ptr->output, ' ', len);
	if ((s_ptr->flags & 4) == 4)
	{
		ft_memcpy(s_ptr->output, "0x0", 3);
		str_fill_char(s_ptr->output + 3, '0', s_ptr->precision - 1);
	}
	else
	{
		str_fill_char(s_ptr->output + len - s_ptr->precision, '0',
			s_ptr->precision);
		if (s_ptr->precision != -1)
			ft_memcpy(s_ptr->output + len - 2 - s_ptr->precision, "0x0", 3);
		else
			ft_memcpy(s_ptr->output + len - 3, "0x0", 3);
	}
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}

int		ft_conv_address(t_conv_id *s_ptr, va_list *arg_ptr)
{
	unsigned long	value;
	int				len;

	get_address_value(&value, arg_ptr);
	len = calc_len_address(s_ptr, value);
	if (value == 0 && s_ptr->precision == 0)
		return (null_ptr_zero(s_ptr, len - 1));
	else if (value == 0)
		return (null_ptr(s_ptr, len));
	len = unsigned_len_base(value, 16);
	len = (len < s_ptr->precision ? s_ptr->precision + 2 : len + 2);
	len = (len < s_ptr->width ? s_ptr->width : len);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if ((s_ptr->flags & 4) == 4)
		minus_flag_address(s_ptr, len, value);
	else
		no_flag_address(s_ptr, len, value);
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
