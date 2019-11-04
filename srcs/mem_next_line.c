/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:28:12 by alagache          #+#    #+#             */
/*   Updated: 2019/11/04 17:45:20 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_data	*init(int fd, t_list **alst)
{
	t_list	*node;
	t_data	*curr;

	node = *alst;
	while (node != NULL)
	{
		curr = (t_data *)(node->content);
		if (curr->fd == fd)
			return (curr);
		node = node->next;
	}
	if (!(node = ft_lstnew(NULL, 0)))
		return (NULL);
	node->content_size = sizeof(t_data);
	if (!(node->content = (malloc(node->content_size))))
		return (NULL);
	curr = (t_data *)(node->content);
	curr->fd = fd;
	curr->read = NULL;
	curr->len = 0;
	ft_lstadd(alst, node);
	return (curr);
}

static int		read_until(t_data *curr)
{
	char	buf[BUFF_SIZE];
	int		ret;
	char	*tmp;

	if (!(curr->read))
	{
		if (!(curr->read = ft_strdup("")))
			return (-1);
	}
	else if (ft_memchr(curr->read, '\n', curr->len) != NULL)
		return (0);
	while ((ret = read(curr->fd, buf, BUFF_SIZE)) > 0)
	{
		if ((tmp = ft_memjoin(curr->read, curr->len, buf, ret)) == NULL)
			return (-1);
		free(curr->read);
		curr->read = tmp;
		curr->len += ret;
		if (ft_memchr(curr->read, '\n', curr->len) != NULL)
			return (0);
	}
	return (0);
}

static char		*fill_line(t_data *curr, char **line)
{
	char	*pos;
	char	*tmp;
	size_t	nl_len;

	if ((pos = ft_memchr(curr->read, '\n', curr->len)) != NULL)
	{
		nl_len = pos - curr->read;
		if ((*line = ft_memalloc(nl_len)) == NULL)
			return (NULL);
		ft_memcpy(*line, curr->read, nl_len);
		if ((tmp = ft_memalloc(curr->len - nl_len - 1)) == NULL)
			return (NULL);
		ft_memcpy(tmp, pos + 1, curr->len - nl_len - 1);
		free(curr->read);
		curr->read = tmp;
		curr->len -= nl_len - 1;
	}
	else
	{
		*line = curr->read;
		curr->read = NULL;
		curr->len = 0;
	}
	return (*line);
}

static void		free_exit(t_list **head, t_data *curr)
{
	t_list	*tmp;
	t_list	*node;

	node = *head;
	while ((t_data *)(node->content) != curr)
	{
		tmp = node;
		node = node->next;
	}
	if (node == *head)
		*head = node->next;
	else
		tmp->next = node->next;
	free(curr);
	free(node);
}

int				mem_next_line(int fd, char **line)
{
	static	t_list	*head = NULL;
	t_data			*curr;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(curr = init(fd, &head)))
		return (-1);
	if (read_until(curr) == -1)
		return (-1);
	if (!(fill_line(curr, line)))
		return (-1);
	if (curr->read == NULL && **line == '\0')
	{
		free_exit(&head, curr);
		return (0);
	}
	else
		return (1);
}
