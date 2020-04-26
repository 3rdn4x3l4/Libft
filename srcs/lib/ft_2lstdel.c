/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:10:57 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 17:42:50 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** take a pointer to pointer on the head, and a pointer to function
** use the function pointer to del every element present in the list
*/

void	ft_2lstdel(t_2list **alst, void (*del)(void *))
{
	if ((*alst)->next)
		ft_2lstdel(&(*alst)->next, del);
	ft_2lstdelone(alst, del);
}
