/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:25:27 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:57:30 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	ft_isalnum(const int c)
{
	if (ft_isalpha(c) == TRUE || ft_isdigit(c) == TRUE)
		return (TRUE);
	return (FALSE);
}
