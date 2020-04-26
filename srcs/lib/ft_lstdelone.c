/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:50:40 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:44:33 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes a pointer to pointer to link and a pointer to function
** use the function to delete the content of the link
** free the link and set its pointer to NULL
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((**alst).content, (**alst).content_size);
	free(*alst);
	*alst = NULL;
}
