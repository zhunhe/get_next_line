/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:57:59 by juhur             #+#    #+#             */
/*   Updated: 2021/11/30 16:58:00 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	return (0);
}
