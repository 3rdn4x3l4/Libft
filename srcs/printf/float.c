/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:30:42 by alagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:34:54 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

int		ft_conv_double(t_conv_id *s_ptr, va_list *arg_ptr)
{
	t_s_e_m		dble;
	int			ret;

	get_double_value(arg_ptr, &dble);
	if ((ret = ft_double_special(s_ptr, &dble)) == -1)
		return (-1);
	else if (ret == -2)
		return (ftoa_double(&dble, s_ptr));
	else
		return (ret);
}

int		ft_conv_ldouble(t_conv_id *s_ptr, va_list *arg_ptr)
{
	t_s_e_m		dble;
	int			ret;

	get_ldouble_value(arg_ptr, &dble);
	if ((ret = ft_longd_special(s_ptr, &dble)) == -1)
		return (-1);
	else if (ret == -2)
		return (ftoa_ldouble(&dble, s_ptr));
	else
		return (ret);
}

int		ft_conv_float(t_conv_id *s_ptr, va_list *arg_ptr)
{
	t_conv_func	func;

	func = (s_ptr->len_modif1 == 'L' ? &ft_conv_ldouble : &ft_conv_double);
	s_ptr->precision = (s_ptr->precision == -1 ? 6 : s_ptr->precision);
	return ((*func)(s_ptr, arg_ptr));
}
