/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:58:10 by plagache          #+#    #+#             */
/*   Updated: 2019/08/13 11:40:29 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg.h"
#include "libft.h"

int			parsing(char *ptr, int end, t_conv_id *struct_ptr)
{
	int	ret;
	int	pos;

	pos = 0;
	struct_ptr->conv = ptr[end];
	if ((pos = flag(ptr, end, struct_ptr)) == -1)
		return (-1);
	if ((ret = width(ptr + pos, (end - pos), struct_ptr)) == -1)
		return (-1);
	pos += ret;
	struct_ptr->precision = -1;
	if (ptr[pos] == '.')
	{
		pos++;
		pos += precision(ptr + pos, (end - pos), struct_ptr);
	}
	pos += len_modifier(ptr + pos, (end - pos), struct_ptr);
	if ((pos - end) == 0)
		return (0);
	return (-1);
}

int			check_conversion(const char *str)
{
	int	c;

	c = 1;
	while (str[c] && ft_strchr("hlL#-+ 0123456789.cspdiouxXf%", str[c]) != 0)
	{
		if ((ft_strchr("cspdiouxXf%", str[c])) != 0)
			return (c);
		c++;
	}
	return (-1);
}

t_point		conv_path(const char *fmt, va_list *arg_ptr)
{
	t_conv_id	conv_info;
	t_conv_func	conv_func;
	t_point		len;

	len.written = 0;
	ft_bzero(&conv_info, sizeof(conv_info));
	if ((len.read = check_conversion(fmt)) == -1)
	{
		len.read = 0;
		return (len);
	}
	if ((len.written = parsing((char*)fmt, len.read, &conv_info)) == -1)
	{
		len.read = 0;
		len.written = 0;
		return (len);
	}
	conv_func = get_func(conv_info.conv);
	len.written = (*conv_func)(&conv_info, arg_ptr);
	return (len);
}

int			loop_conv(const char *fmt, va_list *arg_ptr, int written)
{
	int		chars;
	t_point	ret;
	char	*ptr;

	if ((ptr = ft_strchr(fmt, '%')) == NULL)
	{
		chars = ft_strlen(fmt);
		write(1, fmt, chars);
		return (written + chars);
	}
	else if (fmt == ptr)
	{
		ret = conv_path(fmt, arg_ptr);
		if (ret.written == -1)
			return (-1);
		return (loop_conv(fmt + ret.read + 1, arg_ptr, written + ret.written));
	}
	else
	{
		chars = (int)(ptr - fmt);
		write(1, fmt, chars);
		return (loop_conv(fmt + chars, arg_ptr, written + chars));
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;

	va_start(args, format);
	written = loop_conv(format, &args, 0);
	va_end(args);
	return (written);
}
