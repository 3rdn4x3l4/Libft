/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:17:00 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 19:10:52 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** takes a string and a file descriptor
** write the string on the file descriptor
*/

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}
