/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 03:38:45 by alagache          #+#    #+#             */
/*   Updated: 2020/05/26 03:39:32 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		free_arr(void **arr)
{
	int c;

	c = -1;
	while (arr[++c] != NULL)
		free(arr[c]);
	free(arr);
}
