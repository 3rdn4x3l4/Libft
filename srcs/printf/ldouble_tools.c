/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:44 by alagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:41:32 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void	get_ldouble_value(va_list *arg_ptr, t_s_e_m *dble_ptr)
{
	long double		value;
	unsigned char	tab[16];

	value = va_arg(*arg_ptr, long double);
	ft_memcpy(tab, &value, 16);
	dble_ptr->s = ((tab[9] & 128) == 128 ? 1 : 0);
	dble_ptr->e = (*((unsigned short *)(tab + 8))) & 0x7fff;
	ft_memcpy(&(dble_ptr->m), tab, 8);
}

void	ldouble_mantissa(unsigned long long mant, t_ld_arrs *a_ptr)
{
	int	count;

	count = 64;
	ft_memset(a_ptr->tab, '0', sizeof(a_ptr->tab));
	ft_memset(a_ptr->tmp, '0', sizeof(a_ptr->tmp));
	a_ptr->tmp[5000] = '5';
	while (count != 0)
	{
		if (mant & 0x4000000000000000ULL)
			add_strings(a_ptr->tab, a_ptr->tmp, sizeof(a_ptr->tmp));
		divide_str_by_two(a_ptr->tmp, sizeof(a_ptr->tmp));
		mant <<= 1;
		count--;
	}
}

void	ldouble_exponant(t_s_e_m *dble_ptr, t_ld_arrs *a_ptr)
{
	int		count;
	int		dir;
	void	(*func_ptr) (char *, int);

	count = (dble_ptr->e == 0 ? -16382 : dble_ptr->e - 16383);
	dir = (count < 0 ? 1 : -1);
	func_ptr = (count > 0 ? &multiply_str_by_two : &divide_str_by_two);
	while (count != 0)
	{
		(*func_ptr)(a_ptr->tab, sizeof(a_ptr->tab));
		count += dir;
	}
}

void	ldouble_rounding(t_ld_arrs *a_ptr, t_conv_id *s_ptr)
{
	int	prec;
	int	pos;

	prec = s_ptr->precision;
	if (prec <= 16382)
	{
		if (a_ptr->tab[5000 + prec] > '5' || (a_ptr->tab[5000 + prec] == '5'
			&& (a_ptr->tab[4999 + prec] - 48) % 2 == 1))
			apply_ld_rounding(a_ptr, prec);
		else if (a_ptr->tab[5000 + prec] == '5'
			&& (a_ptr->tab[4999 + prec] - 48) % 2 == 0)
		{
			pos = 1;
			while (a_ptr->tab[350 + prec + pos] == '0' && pos < 14)
				pos++;
			if (pos != 14)
				apply_ld_rounding(a_ptr, prec);
		}
	}
	ft_memset(a_ptr->tab + 5000 + prec, '0', sizeof(a_ptr->tab) - prec - 5000);
}

void	fill_ld_tabs(t_ld_arrs *a_ptr, t_s_e_m *dble_ptr, t_conv_id *s_ptr)
{
	a_ptr->len_i = 0;
	a_ptr->len_f = 0;
	if (dble_ptr->e == 0 && dble_ptr->m == 0)
		ft_memset(a_ptr->tab, '0', (int)sizeof(a_ptr->tab));
	else
	{
		ldouble_mantissa(dble_ptr->m, a_ptr);
		if ((dble_ptr->m >> 63) == 1)
			a_ptr->tab[4999] = '1';
		ldouble_exponant(dble_ptr, a_ptr);
		ldouble_rounding(a_ptr, s_ptr);
	}
	while (a_ptr->len_i < 4999 && a_ptr->tab[a_ptr->len_i] == '0')
		a_ptr->len_i++;
	a_ptr->len_i = (5000 - a_ptr->len_i == 0 ? 1 : 5000 - a_ptr->len_i);
	a_ptr->len_f = (int)(sizeof(a_ptr->tab)) - 1;
	while (a_ptr->len_f > 5000 && a_ptr->tab[a_ptr->len_f] == '0')
		a_ptr->len_f--;
	a_ptr->len_f = (a_ptr->len_f == 5000 ? 0 : (a_ptr->len_f - 4999));
}
