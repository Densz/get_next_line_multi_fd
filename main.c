/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:19:40 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/23 17:42:36 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				main(int ac, char *av[])
{
	int			fd;
	int			fd2;
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
		i = 0;
	fd2 = open(av[2], O_RDONLY);
	while (i < 8)
	{
		printf("%i", get_next_line(fd, &line));
		printf("\x1b[32m%s\n\x1b[0m", line);
		printf("%i", get_next_line(fd2, &line));
		printf("\x1b[32m%s\n\x1b[0m", line);
		i++;
	}
	return (0);
}
