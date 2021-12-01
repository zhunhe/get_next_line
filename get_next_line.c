/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:10 by juhur             #+#    #+#             */
/*   Updated: 2021/12/01 15:27:44 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*free_and_return_null(char **buf1)
{
	if (buf1 && *buf1)
	{
		free(*buf1);
		*buf1 = NULL;
	}
	return (NULL);
}

static char	*read_a_line(int fd, char *save_buf)
{
	char	read_buf[BUFFER_SIZE + 1];
	ssize_t	read_len;

	while (!ft_strchr(read_buf, '\n'))
	{
		read_len = read(fd, read_buf, BUFFER_SIZE);
		if (read_len == -1)
			return (free_and_return_null(&save_buf));
		if (read_len == 0)
			break ;
		read_buf[read_len] = '\0';
		save_buf = ft_strexpand(save_buf, read_buf);
		if (!save_buf)
			return (free_and_return_null(&save_buf));
	}
	return (save_buf);
}

static char	*tidy_static_buf(char **save_buf, size_t trim_len)
{
	char	*string;

	string = ft_strndup(*save_buf + trim_len, ft_strlen(*save_buf) - trim_len);
	if (!string)
		return (free_and_return_null(save_buf));
	free(*save_buf);
	*save_buf = NULL;
	return (string);
}

static char	*get_a_line(char **save_buf)
{
	char	*r_str;
	size_t	r_len;

	r_len = ft_strlen(*save_buf) - ft_strlen(ft_strchr(*save_buf, '\n')) + 1;
	r_str = ft_strndup(*save_buf, r_len);
	if (!r_str)
		return (free_and_return_null(save_buf));
	*save_buf = tidy_static_buf(save_buf, r_len);
	if (!(*save_buf))
		return (free_and_return_null(save_buf));
	return (r_str);
}

char	*get_next_line(int fd)
{
	static char	*save_buf;
	char		*r_str;

	save_buf = read_a_line(fd, save_buf);
	if (!save_buf)
		return (NULL);
	if (ft_strchr(save_buf, '\n'))
		return (get_a_line(&save_buf));
	if (ft_strlen(save_buf) == 0)
		return (free_and_return_null(&save_buf));
	r_str = ft_strndup(save_buf, ft_strlen(save_buf));
	free(save_buf);
	save_buf = NULL;
	if (!r_str)
		return (NULL);
	return (r_str);
}
