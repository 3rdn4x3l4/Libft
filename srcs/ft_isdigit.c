/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:25:41 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:38:53 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a char
** return TRUE if the char is a digit
*/

uint8_t	ft_isdigit(const int c)
{
	if (c <= '9' && c >= '0')
		return (TRUE);
	return (FALSE);
}
