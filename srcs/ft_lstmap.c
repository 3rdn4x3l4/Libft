/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:31:34 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:57:58 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (lst != NULL && f != NULL)
	{
		tmp = f(lst);
		if ((*lst).next != NULL && tmp != NULL)
			(*tmp).next = ft_lstmap((*lst).next, f);
		return (tmp);
	}
	return (NULL);
}
