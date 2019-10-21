/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstadd_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:09:53 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:57:10 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstadd_last(t_2list **alst, t_2list *new)
{
	t_2list	*tmp;

	while ((*alst)->next != NULL)
		tmp = (*alst)->next;
	tmp->next = new;
	new->previous = tmp;
}
