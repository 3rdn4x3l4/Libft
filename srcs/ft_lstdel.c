/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:49:27 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:43:08 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a pointer to pointer to head, and a pointer to function
** recursively calls itself with the next non NULL element to delete the list
** usinf the function pointer to delete the content of every links
*/

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (del != NULL)
	{
		if ((**alst).next)
			ft_lstdel(&(**alst).next, del);
		ft_lstdelone(alst, del);
	}
}
