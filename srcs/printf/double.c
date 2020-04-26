/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:09 by alagache          #+#    #+#             */
/*   Updated: 2019/10/24 16:42:10 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	minus_flag_double(t_d_arrs *a_ptr, t_conv_id *s_ptr, t_s_e_m *dble_ptr,
	int len)
{
	int pos;

	pos = 0;
	str_fill_char(s_ptr->output, ' ', len);
	if (dble_ptr->s == 1)
		s_ptr->output[pos++] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[pos++] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[pos++] = ' ';
	ft_memcpy(s_ptr->output + pos, a_ptr->tab + 350 - a_ptr->len_i,
		a_ptr->len_i);
	if (((s_ptr->precision == 0) && (s_ptr->flags & 1) == 1)
		|| s_ptr->precision != 0)
		s_ptr->output[pos + a_ptr->len_i] = '.';
	if (s_ptr->precision != 0)
		ft_memcpy(s_ptr->output + pos + a_ptr->len_i + 1, a_ptr->tab + 350,
			a_ptr->len_f);
	if (s_ptr->precision > a_ptr->len_f)
		str_fill_char(s_ptr->output + pos + a_ptr->len_i + 1 + a_ptr->len_f,
			'0', s_ptr->precision - a_ptr->len_f);
}

void	zero_flag_double(t_d_arrs *a_ptr, t_conv_id *s_ptr, t_s_e_m *dble_ptr,
	int len)
{
	int	pos;

	str_fill_char(s_ptr->output, '0', len);
	if (dble_ptr->s == 1)
		s_ptr->output[0] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[0] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[0] = ' ';
	if (s_ptr->precision != 0)
		ft_memcpy(s_ptr->output + len - s_ptr->precision, a_ptr->tab + 350,
			a_ptr->len_f);
	if (((s_ptr->precision == 0) && (s_ptr->flags & 1) == 1)
		|| s_ptr->precision != 0)
		s_ptr->output[len - s_ptr->precision - 1] = '.';
	if (ft_strchr(s_ptr->output, '.') == NULL)
		ft_memcpy(s_ptr->output + len - a_ptr->len_i, a_ptr->tab + 350 -
			a_ptr->len_i, a_ptr->len_i);
	else
	{
		pos = ft_strchr(s_ptr->output, '.') - s_ptr->output;
		ft_memcpy(s_ptr->output + pos - a_ptr->len_i, a_ptr->tab + 350 -
			a_ptr->len_i, a_ptr->len_i);
	}
}

void	no_flag_double(t_d_arrs *a_ptr, t_conv_id *s_ptr, t_s_e_m *dble_ptr,
	int len)
{
	int pos;

	str_fill_char(s_ptr->output, ' ', len);
	if (s_ptr->precision > a_ptr->len_f)
		ft_memset(s_ptr->output + len - (s_ptr->precision - a_ptr->len_f), '0',
			(s_ptr->precision - a_ptr->len_f));
	if (s_ptr->precision != 0)
		ft_memcpy(s_ptr->output + len - s_ptr->precision, a_ptr->tab + 350,
			a_ptr->len_f);
	if ((s_ptr->precision == 0 && (s_ptr->flags & 1) == 1)
		|| s_ptr->precision != 0)
		s_ptr->output[len - s_ptr->precision - 1] = '.';
	pos = ft_strrchr(s_ptr->output, ' ') - s_ptr->output;
	ft_memcpy(s_ptr->output + (pos + 1) - a_ptr->len_i, a_ptr->tab + 350 -
		a_ptr->len_i, a_ptr->len_i);
	if (dble_ptr->s == 1)
		s_ptr->output[pos + 1 - a_ptr->len_i - 1] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[pos + 1 - a_ptr->len_i - 1] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[pos + 1 - a_ptr->len_i - 1] = ' ';
}

int		calc_len_double(t_d_arrs *a_ptr, t_conv_id *s_ptr, t_s_e_m *dble_ptr)
{
	int len;
	int	s;

	s = ((s_ptr->flags & 24) != 0 || dble_ptr->s == 1 ? 1 : 0);
	len = a_ptr->len_i;
	if ((s_ptr->precision == 0 && (s_ptr->flags & 1) == 1) ||
			s_ptr->precision != 0)
		len++;
	len += s_ptr->precision;
	len = (s_ptr->width > len + s ? s_ptr->width : len + s);
	return (len);
}

int		ftoa_double(t_s_e_m *dble, t_conv_id *s_ptr)
{
	t_d_arrs	dbl_arr;
	int			len;

	fill_d_tabs(&dbl_arr, dble, s_ptr);
	len = calc_len_double(&dbl_arr, s_ptr, dble);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if ((s_ptr->flags & 4) == 4)
		minus_flag_double(&dbl_arr, s_ptr, dble, len);
	else if ((s_ptr->flags & 2) == 2)
		zero_flag_double(&dbl_arr, s_ptr, dble, len);
	else
		no_flag_double(&dbl_arr, s_ptr, dble, len);
	write(s_ptr->fd, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
