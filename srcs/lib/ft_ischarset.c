/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 21:50:47 by alagache          #+#    #+#             */
/*   Updated: 2020/06/08 21:59:00 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** take a charset a str and a len
** return TRUE if the len chars of str are part of the charset FALSE otherwise
*/

int	ft_ischarset(char *charset, char *str, int len)
{
	int	iterator;

	iterator = -1;
	while (++iterator < len && str[iterator])
	{
		if (ft_strchr(charset, str[iterator]) == NULL)
			return (FALSE);
	}
	return (TRUE);
}
