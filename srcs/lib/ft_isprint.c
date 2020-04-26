/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:13:15 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:39:15 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a char
** return TRUE if the char is printable
*/

uint8_t	ft_isprint(const int c)
{
	if (c >= 32 && c < 127)
		return (TRUE);
	return (FALSE);
}
