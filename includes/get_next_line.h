/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:00:08 by alagache          #+#    #+#             */
/*   Updated: 2019/05/08 13:00:23 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_data
{
	int			fd;
	char		*buffer;
}				t_data;

int				get_next_line(const int fd, char **line);

#endif
