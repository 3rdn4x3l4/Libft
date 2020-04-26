/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:46:36 by alagache          #+#    #+#             */
/*   Updated: 2020/02/14 18:18:15 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** takes two strings, and a code
** calls ft_strjoin using the two strings
** code use bits to determine what string to free
** 00000011 free both string	3
** 00000010 free s2				2
** 00000001 free s1				1
*/

char	*ft_strjoinfree(char *s1, char *s2, char code)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if ((code & 1) != 0)
		free(s1);
	if ((code & 2) != 0)
		free(s2);
	return (ret);
}
