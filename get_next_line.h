/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:23:20 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/23 17:47:52 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <string.h>

# define BUFF_SIZE 10

typedef struct		s_fd
{
	int				n_fd;
	char			*str;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
