/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:10:57 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:57:13 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstdel(t_2list **alst, void (*del)(void *))
{
	if ((*alst)->next)
		ft_2lstdel(&(*alst)->next, del);
	ft_2lstdelone(alst, del);
}
