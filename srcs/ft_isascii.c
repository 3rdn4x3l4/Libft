/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:13:03 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:38:36 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a char
** return TRUE is the char is in the ASCIi table
*/

uint8_t	ft_isascii(const int c)
{
	if (c <= 127 && c >= 0)
		return (TRUE);
	return (FALSE);
}
