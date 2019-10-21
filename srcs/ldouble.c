/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:38 by alagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:42:51 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"
#include <stdio.h>

void	minus_flag_ldouble(t_ld_arrs *a_ptr, t_conv_id *s_ptr,
	t_s_e_m *dble_ptr, int len)
{
	int pos;

	str_fill_char(s_ptr->output, ' ', len);
	s_ptr->output[0] = '0';
	if (dble_ptr->s == 1)
		s_ptr->output[0] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[0] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[0] = ' ';
	pos = (s_ptr->output[0] == '0' ? 0 : 1);
	ft_memcpy(s_ptr->output + pos, a_ptr->tab + 5000 - a_ptr->len_i,
		a_ptr->len_i);
	if (((s_ptr->precision == 0) && (s_ptr->flags & 1) == 1)
		|| s_ptr->precision != 0)
		s_ptr->output[pos + a_ptr->len_i] = '.';
	if (s_ptr->precision != 0)
		ft_memcpy(s_ptr->output + pos + a_ptr->len_i + 1, a_ptr->tab + 5000,
			a_ptr->len_f);
	if (s_ptr->precision > a_ptr->len_f)
		str_fill_char(s_ptr->output + pos + a_ptr->len_i + 1 + a_ptr->len_f,
			'0', s_ptr->precision - a_ptr->len_f);
}

void	zero_flag_ldouble(t_ld_arrs *a_ptr, t_conv_id *s_ptr,
	t_s_e_m *dble_ptr, int len)
{
	int pos;

	str_fill_char(s_ptr->output, '0', len);
	if (dble_ptr->s == 1)
		s_ptr->output[0] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[0] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[0] = ' ';
	if (s_ptr->precision != 0)
		ft_memcpy(s_ptr->output + len - s_ptr->precision, a_ptr->tab + 5000,
			a_ptr->len_f);
	if (((s_ptr->precision == 0) && (s_ptr->flags & 1) == 1)
		|| s_ptr->precision != 0)
		s_ptr->output[len - s_ptr->precision - 1] = '.';
	if (ft_strchr(s_ptr->output, '.') == NULL)
		ft_memcpy(s_ptr->output + len - a_ptr->len_i, a_ptr->tab + 5000 -
			a_ptr->len_i, a_ptr->len_i);
	else
	{
		pos = ft_strchr(s_ptr->output, '.') - s_ptr->output;
		ft_memcpy(s_ptr->output + pos - a_ptr->len_i, a_ptr->tab + 5000 -
			a_ptr->len_i, a_ptr->len_i);
	}
}

void	no_flag_ldouble(t_ld_arrs *a_ptr, t_conv_id *s_ptr, t_s_e_m *dble_ptr,
	int len)
{
	int	pos;

	str_fill_char(s_ptr->output, ' ', len);
	if (s_ptr->precision > a_ptr->len_f)
		ft_memset(s_ptr->output + len - (s_ptr->precision - a_ptr->len_f), '0',
			(s_ptr->precision - a_ptr->len_f));
	if (s_ptr->precision != 0)
		ft_memcpy(s_ptr->output + len - s_ptr->precision, a_ptr->tab + 5000,
			a_ptr->len_f);
	if (((s_ptr->precision == 0) && (s_ptr->flags & 1) == 1)
		|| s_ptr->precision != 0)
		s_ptr->output[len - s_ptr->precision - 1] = '.';
	pos = ft_strrchr(s_ptr->output, ' ') - s_ptr->output;
	ft_memcpy(s_ptr->output + (pos + 1) - a_ptr->len_i, a_ptr->tab + 5000 -
		a_ptr->len_i, a_ptr->len_i);
	if (dble_ptr->s == 1)
		s_ptr->output[pos + 1 - a_ptr->len_i - 1] = '-';
	else if ((s_ptr->flags & 16) == 16)
		s_ptr->output[pos + 1 - a_ptr->len_i - 1] = '+';
	else if ((s_ptr->flags & 8) == 8)
		s_ptr->output[pos + 1 - a_ptr->len_i - 1] = ' ';
}

int		calc_len_ldouble(t_ld_arrs *a_ptr, t_conv_id *s_ptr, t_s_e_m *dble_ptr)
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

int		ftoa_ldouble(t_s_e_m *dble, t_conv_id *s_ptr)
{
	t_ld_arrs	dbl_arr;
	int			len;

	fill_ld_tabs(&dbl_arr, dble, s_ptr);
	len = calc_len_ldouble(&dbl_arr, s_ptr, dble);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if ((s_ptr->flags & 4) == 4)
		minus_flag_ldouble(&dbl_arr, s_ptr, dble, len);
	else if ((s_ptr->flags & 2) == 2)
		zero_flag_ldouble(&dbl_arr, s_ptr, dble, len);
	else
		no_flag_ldouble(&dbl_arr, s_ptr, dble, len);
	write(1, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
