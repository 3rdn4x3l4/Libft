/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:17:11 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 19:08:08 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a string and a file descriptor
** write the string followed by a newline on the given file descriptor
*/

void	ft_putendl_fd(char const *s, int fd)
{
	if (!(s == NULL))
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
