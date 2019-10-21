/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:47:06 by alagache          #+#    #+#             */
/*   Updated: 2019/04/25 10:57:19 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_2lstdelone(t_2list **alst, void (*del)(void *))
{
	del((*alst)->cntent);
	free(*alst);
	*alst = NULL;
}
