/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:31:58 by alagache          #+#    #+#             */
/*   Updated: 2019/10/24 16:36:24 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "libft.h"

void		minus_string(t_conv_id *s_ptr, int len, char *str)
{
	str_fill_char(s_ptr->output, ' ', len);
	if (s_ptr->precision != -1)
		ft_memcpy(s_ptr->output, str, s_ptr->precision);
	else
		ft_memcpy(s_ptr->output, str, (int)ft_strlen(str));
}

int			null_string(t_conv_id *s_ptr)
{
	int len;

	s_ptr->precision = (s_ptr->precision != -1 && s_ptr->precision <= 6 ?
		s_ptr->precision : 6);
	len = (s_ptr->width > s_ptr->precision ? s_ptr->width : s_ptr->precision);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	str_fill_char(s_ptr->output, ' ', len);
	if ((s_ptr->precision != -1) &&
		(s_ptr->flags & 4) == 4)
		ft_memcpy(s_ptr->output, "(null)", s_ptr->precision);
	else if (s_ptr->precision != -1)
		ft_memcpy(s_ptr->output + (len - s_ptr->precision), "(null)",
			s_ptr->precision);
	write(s_ptr->fd, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}

void		no_flag_string(t_conv_id *s_ptr, int len, char *str)
{
	int len_o;

	len_o = (int)ft_strlen(str);
	str_fill_char(s_ptr->output, ' ', len);
	if (s_ptr->precision != -1 && s_ptr->precision > len_o)
		ft_memcpy(s_ptr->output + (len - len_o), str, len_o);
	else if (s_ptr->precision != -1)
		ft_memcpy(s_ptr->output + (len - s_ptr->precision), str,
			s_ptr->precision);
	else
		ft_memcpy(s_ptr->output + (len - len_o), str, len_o);
}

int			calc_len_string(t_conv_id *s_ptr, char *str)
{
	int	len;

	len = (s_ptr->precision != -1 ? s_ptr->precision : (int)ft_strlen(str));
	len = (len > (int)ft_strlen(str) ? (int)ft_strlen(str) : len);
	len = (s_ptr->width > len ? s_ptr->width : len);
	return (len);
}

int			ft_conv_string(t_conv_id *s_ptr, va_list *arg_ptr)
{
	int		len;
	char	*str;

	str = (char *)va_arg(*arg_ptr, char *);
	if (str == NULL)
		return (null_string(s_ptr));
	if (ft_strlen(str) == 0)
		s_ptr->precision = -1;
	len = calc_len_string(s_ptr, str);
	if (!(s_ptr->output = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	s_ptr->output[len] = '\0';
	if ((s_ptr->flags & 4) == 4)
		minus_string(s_ptr, len, str);
	else
		no_flag_string(s_ptr, len, str);
	write(s_ptr->fd, s_ptr->output, len);
	free(s_ptr->output);
	return (len);
}
