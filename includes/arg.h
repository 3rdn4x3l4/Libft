/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:21:25 by plagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:34:12 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

# define FLAGSMAX 5
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_conv_info
{
	char	*output;
	char	conv;
	char	len_modif1;
	char	len_modif2;
	int		precision;
	int		width;
	char	flags;
}				t_conv_id;

typedef struct	s_double
{
	char				s;
	unsigned short		e;
	unsigned long long	m;
	char				*str;
}				t_s_e_m;

typedef struct	s_double_arrs
{
	char	tmp[1500];
	char	tab[1500];
	char	*total;
	int		len_i;
	int		len_f;
}				t_d_arrs;

typedef struct	s_long_double_arrs
{
	char	tmp[21500];
	char	tab[21500];
	char	*total;
	int		len_i;
	int		len_f;
}				t_ld_arrs;

typedef struct	s_point
{
	int	read;
	int	written;
}				t_point;

/*
** conversion functions
*/

int				ft_conv_char(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_string(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_address(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_float(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_double(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_ldouble(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_decimal(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_int(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_octal(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_unsigned(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_hexa(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_hexa_upper(t_conv_id *struct_ptr, va_list *arg_ptr);
int				ft_conv_percent(t_conv_id *struct_ptr, va_list *arg_ptr);

/*
** typedef for conversion functions
*/

typedef int		(*t_conv_func)(t_conv_id *struct_ptr, va_list *arg_ptr);
t_conv_func		get_func(char c);

/*
** parsing functions
*/

int				flag(char *ptr, int end, t_conv_id *struct_ptr);
int				width(char *ptr, int end, t_conv_id *struct_ptr);
int				precision(char *ptr, int end, t_conv_id *struct_ptr);
int				len_modifier(char *ptr, int end, t_conv_id *struct_ptr);

/*
** int tools
*/
int				check_int_struct(t_conv_id *ptr);
void			get_int_value(long long int	*val_ptr, va_list *arg_ptr,
				t_conv_id *s_ptr);
int				int_len(long long int val);
int				calc_len_int(t_conv_id *s_ptr, long long int value);

/*
** unsigned tools
*/

int				check_unsigned_struct(t_conv_id *ptr);
void			get_unsigned_value(unsigned long long *val_ptr,
				va_list *arg_ptr, t_conv_id *s_ptr);
int				calc_len_unsigned(t_conv_id *s_ptr, unsigned long long value);
int				unsigned_len(unsigned long long val);

/*
** octal_tools
*/
int				check_octal_struct(t_conv_id *s_ptr);
int				calc_len_octal(t_conv_id *s_ptr, unsigned long long value);

/*
** hexa_tools
*/
int				calc_len_hexa(t_conv_id *s_ptr, unsigned long long value);

/*
** address_tools
*/
void			get_address_value(unsigned long *val_ptr, va_list *arg_ptr);
int				calc_len_address(t_conv_id *s_ptr, unsigned long value);

/*
** float_tools
*/
int				ftoa_double(t_s_e_m *dble, t_conv_id *s_ptr);
int				ftoa_ldouble(t_s_e_m *dble, t_conv_id *s_ptr);

/*
** double_tools
*/
void			get_double_value(va_list *arg_ptr, t_s_e_m *dble_ptr);
int				ft_double_special(t_conv_id *s_ptr, t_s_e_m *dble);
void			add_strings(char *dst, char *src, int len);
void			multiply_str_by_two(char *str, int len);
void			divide_str_by_two(char *str, int len);
void			fill_d_tabs(t_d_arrs *a_ptr, t_s_e_m *dble_ptr,
				t_conv_id *s_ptr);
void			double_exponant(t_s_e_m *dble_ptr, t_d_arrs *a_ptr);
void			double_mantissa(t_s_e_m *dble_ptr, t_d_arrs *a_ptr);
void			apply_d_rounding(t_d_arrs *a_ptr, int prec);

/*
** ldouble_tools
*/
void			get_ldouble_value(va_list *arg_ptr, t_s_e_m *dble_ptr);
int				ft_longd_special(t_conv_id *s_ptr, t_s_e_m *dble);
void			fill_ld_tabs(t_ld_arrs *a_ptr, t_s_e_m *dble_ptr,
				t_conv_id *s_ptr);
void			apply_ld_rounding(t_ld_arrs *a_ptr, int prec);

/*
** special_tools
*/
void			special_value(t_s_e_m *dble_ptr, t_conv_id *s_ptr,
				int len);
void			minus_special_value(t_s_e_m *dble_ptr,
				t_conv_id *s_ptr);

/*
** global tools
*/
int				unsigned_len_base(unsigned long long val, unsigned base);
int				str_fill_char(char *str, char c, int len);

#endif
