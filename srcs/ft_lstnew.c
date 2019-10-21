/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:07:27 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:57:59 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	if (!(new_link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		(*new_link).content = NULL;
		(*new_link).content_size = 0;
	}
	else
	{
		if (!((*new_link).content = (void*)malloc(content_size)))
			return (NULL);
		(*new_link).content = ft_memmove((*new_link).content, content,
		content_size);
		(*new_link).content_size = content_size;
	}
	(*new_link).next = NULL;
	return (new_link);
}
