/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:24 by juhur             #+#    #+#             */
/*   Updated: 2021/11/30 12:48:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

/*
** if BUFFER_SIZE is not natural number, set to BUFFER_SIZE integer 42.
*/
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE <= 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 42
#  endif
# else
#  define BUFFER_SIZE 42
# endif

/*
** get_next_line.c
*/
char	*get_next_line(int fd);

/*
** get_next_line_utils.c
*/
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strexpand(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
#endif
