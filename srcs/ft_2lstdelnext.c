/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstdelnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:11:05 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 17:44:23 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** take a pointer to pointer to link and a pointer to function
** use the function pointer to del the next element of the link
*/

void	ft_2lstdelnext(t_2list **alst, void (*del)(void *))
{
	ft_2lstdelone(&(*alst)->next, del);
}
