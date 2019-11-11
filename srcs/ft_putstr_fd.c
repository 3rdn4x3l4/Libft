/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:17:00 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:58:56 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}
