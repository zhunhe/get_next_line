/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:46 by juhur             #+#    #+#             */
/*   Updated: 2021/11/27 19:18:35 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

/*
** strlen -- find length of string <string.h>
*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/*
** strndup -- save a copy of a string <string.h>
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*string;
	size_t	len;
	size_t	idx;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		string[idx] = s1[idx];
		idx++;
	}
	string[idx] = '\0';
	return (string);
}

/*
** Allocates (with malloc(3)) and returns a new string,
** which is the result of the concatenation of ’s1’ and ’s2’.
*/

char	*ft_strexpand(char *s1, char *s2)
{
	char	*string;
	size_t	idx;
	size_t	len;

	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	idx = 0;
	while (s1 != NULL && s1[idx] != '\0')
	{
		string[idx] = s1[idx];
		idx++;
	}
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	while (*s2 != '\0')
		string[idx++] = *(s2++);
	string[idx] = '\0';
	return (string);
}

/*
** strchr -- locate character in string <string.h>
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
