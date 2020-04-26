/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:14:01 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 19:09:52 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** takes a string
** write the string on the stdout
*/

void	ft_putstr(char const *s)
{
	int	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
}
