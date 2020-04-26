/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:15 by alagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:37:20 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	get_double_value(va_list *arg_ptr, t_s_e_m *dble_ptr)
{
	double		value;

	value = va_arg(*arg_ptr, double);
	ft_memcpy(&(dble_ptr->m), &value, 8);
	dble_ptr->s = (((dble_ptr->m) & 0x8000000000000000ULL) == 0 ? 0 : 1);
	dble_ptr->e = ((dble_ptr->m) >> 52) & 0x7ffULL;
	dble_ptr->m = ((dble_ptr->m) << 12) >> 12;
	dble_ptr->s = (dble_ptr->s == 1 ? 1 : 0);
}

void	double_mantissa(t_s_e_m *dble_ptr, t_d_arrs *a_ptr)
{
	int	count;

	count = 52;
	ft_memset(a_ptr->tab, '0', sizeof(a_ptr->tab));
	ft_memset(a_ptr->tmp, '0', sizeof(a_ptr->tmp));
	a_ptr->tmp[350] = '5';
	while (count != 0)
	{
		if (dble_ptr->m & 0x8000000000000ULL)
			add_strings(a_ptr->tab, a_ptr->tmp, sizeof(a_ptr->tmp));
		divide_str_by_two(a_ptr->tmp, sizeof(a_ptr->tmp));
		dble_ptr->m <<= 1;
		count--;
	}
}

void	double_exponant(t_s_e_m *dble_ptr, t_d_arrs *a_ptr)
{
	int		count;
	int		dir;
	void	(*func_ptr) (char *, int);

	count = dble_ptr->e - 1023;
	dir = (count < 0 ? 1 : -1);
	func_ptr = (count > 0 ? &multiply_str_by_two : &divide_str_by_two);
	if (dble_ptr->e == 0)
		multiply_str_by_two(a_ptr->tab, sizeof(a_ptr->tab));
	while (count != 0)
	{
		(*func_ptr)(a_ptr->tab, sizeof(a_ptr->tab));
		count += dir;
	}
}

void	double_rounding(t_d_arrs *a_ptr, t_conv_id *s_ptr)
{
	int	prec;
	int	pos;

	prec = s_ptr->precision;
	if (prec <= 1022)
	{
		if (a_ptr->tab[350 + prec] > '5' || (a_ptr->tab[350 + prec] == '5'
			&& (a_ptr->tab[349 + prec] - 48) % 2 == 1))
			apply_d_rounding(a_ptr, prec);
		else if (a_ptr->tab[350 + prec] == '5'
				&& (a_ptr->tab[349 + prec] - 48) % 2 == 0)
		{
			pos = 1;
			while (a_ptr->tab[350 + prec + pos] == '0' && pos < 14)
				pos++;
			if (pos != 14)
				apply_d_rounding(a_ptr, prec);
		}
	}
	ft_memset(a_ptr->tab + 350 + prec, '0', sizeof(a_ptr->tab) - prec - 350);
}

void	fill_d_tabs(t_d_arrs *a_ptr, t_s_e_m *dble_ptr, t_conv_id *s_ptr)
{
	a_ptr->len_i = 0;
	a_ptr->len_f = 0;
	if (dble_ptr->e == 0 && dble_ptr->m == 0)
		ft_memset(a_ptr->tab, '0', (int)sizeof(a_ptr->tab));
	else
	{
		double_mantissa(dble_ptr, a_ptr);
		if (dble_ptr->e != 0)
			a_ptr->tab[349] = '1';
		double_exponant(dble_ptr, a_ptr);
		double_rounding(a_ptr, s_ptr);
	}
	while (a_ptr->len_i < 349 && a_ptr->tab[a_ptr->len_i] == '0')
		a_ptr->len_i++;
	a_ptr->len_i = (350 - a_ptr->len_i == 0 ? 1 : 350 - a_ptr->len_i);
	a_ptr->len_f = (int)(sizeof(a_ptr->tab)) - 1;
	while (a_ptr->len_f > 350 && a_ptr->tab[a_ptr->len_f] == '0')
		a_ptr->len_f--;
	a_ptr->len_f = (a_ptr->len_f == 350 ? 0 : (a_ptr->len_f - 349));
}
