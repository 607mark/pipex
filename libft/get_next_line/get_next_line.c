/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/22 14:59:54 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	initialize(char **line, char **nl_p, char *buffer, int fd)
{
	if (fd < 0)
		return (0);
	*line = NULL;
	*nl_p = find_nl(buffer);
	return (1);
}

static ssize_t	read_file(int fd, char *buffer, char **line)
{
	ssize_t		bytes_read;

	gnl_bzero(buffer, BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if ((bytes_read == 0 && **line == '\0') || bytes_read == -1)
	{
		free(*line);
		return (-1);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	char			*nl_p;
	ssize_t			bytes_read;

	if (!initialize(&line, &nl_p, buffer, fd))
		return (NULL);
	while (nl_p == NULL)
	{
		line = join_gnl(line, buffer, gnl_strlen(buffer));
		if (!line)
			return (NULL);
		bytes_read = read_file(fd, buffer, &line);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			return (line);
		nl_p = find_nl(buffer);
	}
	line = join_gnl(line, buffer, (nl_p - buffer) + 1);
	if (!line)
		return (NULL);
	copy_mem(buffer, nl_p + 1, gnl_strlen(nl_p + 1) + 1);
	return (line);
}
