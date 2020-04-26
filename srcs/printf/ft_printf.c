/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:58:10 by plagache          #+#    #+#             */
/*   Updated: 2019/10/28 13:37:56 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;

	va_start(args, format);
	written = loop(1, format, &args, 0);
	va_end(args);
	return (written);
}
