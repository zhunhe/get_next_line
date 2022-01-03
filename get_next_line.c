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

/*
** get_a_line() is a function that returns a string.
*/
static char	*get_a_line(char **save_buf)
{
	char	*line;
	size_t	trim_len;
	char	*trim;

	if (ft_strchr(*save_buf, '\n') == NULL)
	{
		line = ft_strndup(*save_buf, ft_strlen(*save_buf));
		if (line == NULL)
			return (NULL);
		free(*save_buf);
		*save_buf = NULL;
		return (line);
	}
	trim_len = ft_strchr(*save_buf, '\n') - *save_buf + 1;
	line = ft_strndup(*save_buf, trim_len);
	if (line == NULL)
		return (NULL);
	trim = ft_strndup(*save_buf + trim_len, ft_strlen(*save_buf) - trim_len);
	if (trim == NULL)
		return (NULL);
	free(*save_buf);
	*save_buf = trim;
	return (line);
}

/*
** get_next_line() is a function that reads a data using fd and returns a line
** include the '\n', except if it reached the eof and there is no '\n'.
** return NULL if an error has occurred or there is nothing more to read.
*/
char	*get_next_line(int fd)
{
	static char	*save_buf;
	char		read_buf[BUFFER_SIZE + 1];
	ssize_t		read_len;

	while (1)
	{
		read_len = read(fd, read_buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		read_buf[read_len] = '\0';
		save_buf = ft_strexpand(save_buf, read_buf);
		if (save_buf == NULL || ft_strchr(save_buf, '\n'))
			break ;
	}
	if (read_len < 0 || save_buf == NULL)
		return (NULL);
	if (ft_strlen(save_buf) == 0)
	{
		free(save_buf);
		save_buf = NULL;
		return (NULL);
	}
	return (get_a_line(&save_buf));
}
