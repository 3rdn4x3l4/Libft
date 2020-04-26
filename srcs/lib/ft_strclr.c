/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:04:38 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 17:58:44 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a string
** set every char inside the string to '\0'
*/

void	ft_strclr(char *s)
{
	if (s != NULL)
	{
		ft_memset(s, 0, ft_strlen(s));
	}
}
