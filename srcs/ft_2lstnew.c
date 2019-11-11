/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:11:12 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:57:22 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_2list	*ft_2lstnew(void const *cntent, size_t cntent_size)
{
	t_2list	*new_2link;

	new_2link = (t_2list *)malloc(sizeof(t_2list));
	if (new_2link == NULL)
		return (NULL);
	if (cntent == NULL)
		new_2link->cntent = NULL;
	else
	{
		new_2link->cntent = (void *)malloc(sizeof(cntent));
		if (new_2link->cntent == NULL)
			return (NULL);
		new_2link->cntent = ft_memmove(new_2link->cntent, cntent, cntent_size);
	}
	new_2link->next = NULL;
	new_2link->previous = NULL;
	return (new_2link);
}
