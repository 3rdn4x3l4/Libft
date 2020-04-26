/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:47:06 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 17:46:11 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** takes a pointer to pointer to link and function pointer
** use the function pointer delete the content of the link then free the link
** also set the pointer to link to NULL
*/

void	ft_2lstdelone(t_2list **alst, void (*del)(void *))
{
	del((*alst)->cntent);
	free(*alst);
	*alst = NULL;
}
