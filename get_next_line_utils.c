/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:46 by juhur             #+#    #+#             */
/*   Updated: 2022/01/03 15:37:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

/*
** strlen -- find length of string <string.h>
*/
size_t	ft_strlen(const char *s)
{
	const char	*len;

	len = s;
	while (*len != '\0')
		len++;
	return (len - s);
}

/*
** strlcat -- size-bounded string copying and concatenation <string.h>
*/
static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (ft_strlen(src) + dstsize);
	idx = 0;
	while ((dst_len < dstsize - 1)
		&& (src[idx]) != '\0')
		dst[dst_len++] = src[idx++];
	dst[dst_len] = '\0';
	return (dst_len);
}

/*
** strndup -- save a copy of a string <string.h>
*/
char	*ft_strndup(const char *s1, size_t n)
{
	char	*string;
	size_t	len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	*string = '\0';
	ft_strlcat(string, s1, len + 1);
	return (string);
}

/*
** Allocates (with malloc(3)) and returns a 'new' string,
** which is the result of the concatenation of ’old’ and ’s’. And frees 'old'
*/
char	*ft_strexpand(char *old, char *s)
{
	char	*new;
	size_t	old_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (old == NULL)
		return (ft_strndup(s, s_len));
	old_len = ft_strlen(old);
	new = (char *)malloc(sizeof(char) * (old_len + s_len + 1));
	if (new == NULL)
		return (NULL);
	*new = '\0';
	ft_strlcat(new, old, old_len + 1);
	free(old);
	ft_strlcat(new, s, old_len + s_len + 1);
	return (new);
}

/*
** strchr -- locate character in string <string.h>
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
