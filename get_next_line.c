/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:10 by juhur             #+#    #+#             */
/*   Updated: 2022/01/12 13:58:34 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/*
** read_a_line() is a function that reads a string from fd
** until it includes '\n' or reaches eof.
** If the result of the read() function is an error (-1),
** return -1, otherwise return length of read buffer.
*/
static ssize_t	read_a_line(int fd, char **backup)
{
	char	read_buf[BUFFER_SIZE + 1];
	ssize_t	read_len;

	read_len = 0;
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
** get_a_line() is a function that returns a string including '\n'.
*/
static char	*get_a_line(char **backup)
{
	char	*line;
	size_t	trim_len;
	char	*trim;

	trim_len = ft_strchr(*backup, '\n') - *backup + 1;
	line = ft_strndup(*backup, trim_len);
	if (line == NULL)
		return (NULL);
	trim = ft_strndup(*backup + trim_len, ft_strlen(*backup) - trim_len);
	if (trim == NULL)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
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
	char		*line;

	read_len = read_a_line(fd, &backup);
	if (read_len == -1 || backup == NULL)
		return (NULL);
	if (ft_strchr(backup, '\n') != NULL)
		return (get_a_line(&backup));
	if (ft_strlen(backup) == 0)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	line = ft_strndup(backup, ft_strlen(backup));
	if (line == NULL)
		return (NULL);
	free(backup);
	backup = NULL;
	return (line);
}
