/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:32:39 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:06:46 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a pointer to string
** free the string and set the pointer to NULL
*/

void	ft_strdel(char **as)
{
	if (!(as == NULL))
	{
		free(*as);
		*as = NULL;
	}
}
