/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:10 by juhur             #+#    #+#             */
/*   Updated: 2021/12/02 13:20:45 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static ssize_t	read_a_line(int fd, char **backup)
{
	char		read_buf[BUFFER_SIZE + 1];
	ssize_t		read_len;

	while (*backup == NULL || ft_strchr(*backup, '\n') == NULL)
	{
		read_len = read(fd, read_buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		read_buf[read_len] = '\0';
		*backup = ft_strexpand(*backup, read_buf);
		if (*backup == NULL)
			break ;
	}
	return (read_len);
}

/*
** get_a_line() is a function that returns a string.
*/
static char	*get_a_line(char **backup)
{
	char	*line;
	size_t	trim_len;
	char	*trim;

	if (ft_strchr(*backup, '\n') == NULL)
	{
		line = ft_strndup(*backup, ft_strlen(*backup));
		if (line == NULL)
			return (NULL);
		free(*backup);
		*backup = NULL;
		return (line);
	}
	trim_len = ft_strchr(*backup, '\n') - *backup + 1;
	line = ft_strndup(*backup, trim_len);
	if (line == NULL)
		return (NULL);
	trim = ft_strndup(*backup + trim_len, ft_strlen(*backup) - trim_len);
	if (trim == NULL)
		return (NULL);
	free(*backup);
	*backup = trim;
	return (line);
}

/*
** get_next_line() is a function that reads a data using fd and returns a line
** include the '\n', except if it reached the eof and there is no '\n'.
** return NULL if an error has occurred or there is nothing more to read.
*/
char	*get_next_line(int fd)
{
	static char	*backup;
	ssize_t		read_len;

	read_len = read_a_line(fd, &backup);
	if (read_len == -1 || backup == NULL)
		return (NULL);
	if (ft_strlen(backup) == 0)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	return (get_a_line(&backup));
}
