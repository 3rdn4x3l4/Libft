/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstadd_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:58:42 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 17:42:21 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a pointer to pointer on the head, and a link
** adds the link in place of the point to pointer on head
*/

void	ft_2lstadd_first(t_2list **alst, t_2list *new)
{
	(*alst)->previous = new;
	new->next = *alst;
	*alst = new;
}
