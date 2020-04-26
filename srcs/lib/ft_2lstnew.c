/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:11:12 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 17:52:24 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** take a pointer to a malloced zone and the size in bytes of this zone
** allocates a new_2link and set its memory content to 0
** populate its content with the zone passed as argument if it is non NULL
*/

t_2list	*ft_2lstnew(void const *cntent, size_t cntent_size)
{
	t_2list	*new_2link;

	new_2link = (t_2list *)malloc(sizeof(t_2list));
	if (new_2link == NULL)
		return (NULL);
	ft_memset(new_2link, 0, sizeof(t_2list));
	if (cntent != NULL)
	{
		new_2link->cntent = (void *)malloc(sizeof(cntent));
		if (new_2link->cntent == NULL)
			return (NULL);
		new_2link->cntent = ft_memmove(new_2link->cntent, cntent, cntent_size);
	}
	return (new_2link);
}
