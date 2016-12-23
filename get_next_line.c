/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:23:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/23 17:50:20 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd			*checkfd_orcreateit(t_list **lst, const int fd)
{
	t_fd		content;
	t_list		*lst_temp;

	if (fd < 0 || !lst)
		return (NULL);
	lst_temp = *lst;
	while (lst_temp)
	{
		if (((t_fd *)(lst_temp->content))->n_fd == fd)
			return (lst_temp->content);
		lst_temp = lst_temp->next;
	}
	content.n_fd = fd;
	if (!(content.str = ft_strnew(0)))
		return (NULL);
	if (!(lst_temp = ft_lstnew(&content, sizeof(content))))
	{
		free(content.str);
		return (NULL);
	}
	ft_lstadd(lst, lst_temp);
	return ((*lst)->content);
}

int				checkendofline(t_fd *save, char **line)
{
	t_fd		*ptr;
	char		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	ptr = save;
	if (ptr->str)
		if (ft_strchr(ptr->str, '\n') != NULL)
		{
			tmp = ft_strchr(ptr->str, '\n');
			*tmp = '\0';
			while (ptr->str[i])
			{
				if (ptr->str[i] == '\n')
					ptr->str[i] = '\0';
				i++;
			}
			*line = ft_strdup(ptr->str);
			ptr->str = ft_strdup(&tmp[1]);
			tmp = NULL;
			free(tmp);
			return (1);
		}
	return (0);
}

int				whileread(const int fd, char *buf, t_fd *save, char **line)
{
	int			ret;
	t_fd		*ptr;
	char		*tmp;
	int			i;

	i = 0;
	ptr = save;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(ptr->str, buf);
		if (!tmp)
			return (-1);
		free(ptr->str);
		ptr->str = tmp;
		if (checkendofline(save, line))
		{
			free(tmp);
			return (1);
		}
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_fd			*save;
	static t_list	*lst;

	if (!(save = checkfd_orcreateit(&lst, fd)))
		return (-1);
	if (checkendofline(save, line))
		return (1);
	if (whileread(fd, buf, save, line) > 0)
		return (1);
	else if (whileread(fd, buf, save, line) < 0)
		return (-1);
	if (save->str)
	{
		*line = ft_strdup(save->str);
		if (ft_strlen(save->str) == 0)
			return (0);
		save->str = NULL;
		return (1);
	}
	return (0);
}
