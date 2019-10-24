/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:58:10 by plagache          #+#    #+#             */
/*   Updated: 2019/10/24 16:27:34 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;

	va_start(args, format);
	written = loop_conv(1, format, &args, 0);
	va_end(args);
	return (written);
}
