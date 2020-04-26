/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:07:27 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 19:11:51 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a pointer to a memory zone and its size
** allocate a link setits memory to zero
** move thec content of the memory zone inside of content of the link
** if it is non NULL and return the newly allocated link
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	new_link = (t_list*)malloc(sizeof(t_list));
	if (new_link == NULL)
		return (NULL);
	ft_memset(new_link, 0, sizeof(t_list));
	if (content != NULL)
	{
		(*new_link).content = (void*)malloc(content_size);
		if ((*new_link).content == NULL)
			return (NULL);
		(*new_link).content = ft_memmove((*new_link).content, content,
		content_size);
		(*new_link).content_size = content_size;
	}
	return (new_link);
}
