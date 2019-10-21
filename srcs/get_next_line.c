/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 08:59:39 by alagache          #+#    #+#             */
/*   Updated: 2019/05/08 12:59:31 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_data	*init(int fd, t_list **alst)
{
	t_list	*node;
	t_data	*current;

	node = *alst;
	while (node != NULL)
	{
		current = (t_data *)(node->content);
		if (current->fd == fd)
			return (current);
		node = node->next;
	}
	if (!(node = ft_lstnew(NULL, 0)))
		return (NULL);
	node->content_size = sizeof(t_data);
	if (!(node->content = (malloc(node->content_size))))
		return (NULL);
	current = (t_data *)(node->content);
	current->fd = fd;
	current->buffer = NULL;
	ft_lstadd(alst, node);
	return (current);
}

int		read_until(t_data *current)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		old_chars;
	char	*tmp;

	if (!(current->buffer))
	{
		if (!(current->buffer = ft_strdup("\0")))
			return (-1);
	}
	else if (ft_strchr(current->buffer, '\n') != NULL)
		return (0);
	ret = 0;
	old_chars = 0;
	while ((ret = read(current->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(current->buffer, buff);
		free(current->buffer);
		current->buffer = tmp;
		if (ft_strchr((current->buffer) + old_chars, '\n') != NULL)
			return (old_chars);
		old_chars += ret;
	}
	return (ret);
}

char	*fill_line(t_data *current, char **line, int old_chars)
{
	char	*pos;
	char	*tmp;
	size_t	nl_len;

	if ((pos = ft_strchr(current->buffer + old_chars, '\n')) != NULL)
	{
		nl_len = pos - current->buffer;
		if (!(*line = ft_strsub(current->buffer, 0, nl_len)))
			return (NULL);
		if (!(tmp = ft_strdup(pos + 1)))
			return (NULL);
		free(current->buffer);
		current->buffer = tmp;
	}
	else
	{
		*line = current->buffer;
		current->buffer = NULL;
	}
	return (*line);
}

void	free_exit(t_list **head, t_data *current)
{
	t_list	*tmp;
	t_list	*node;

	node = *head;
	while ((t_data *)(node->content) != current)
	{
		tmp = node;
		node = node->next;
	}
	if (node == *head)
		*head = node->next;
	else
		tmp->next = node->next;
	free(current);
	free(node);
}

int		get_next_line(int fd, char **line)
{
	static	t_list	*head = NULL;
	t_data			*current;
	int				old_chars;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(current = init(fd, &head)))
		return (-1);
	if ((old_chars = read_until(current)) == -1)
		return (-1);
	if (!(fill_line(current, line, old_chars)))
		return (-1);
	if (current->buffer == NULL && **line == '\0')
	{
		free_exit(&head, current);
		return (0);
	}
	else
		return (1);
}
