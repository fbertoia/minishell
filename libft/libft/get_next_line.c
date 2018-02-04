/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:53:18 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/17 12:14:01 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 						GET_NEXT_LINE
** This function aims at reading line by line what is written into a file.
** Among parameters, it requires a file descriptor number (so the file needs
** to be opened before launching the function), and a pointer on which memory
** will be allocated.
**
** It returns :
** 		- (-1) in case any error happened during the reading or the memory
** 		allocation, or the parameters are wrong.
** 		- (1) if anything was read, (in order to put the function into a cycle
** 		and to continue reading as long as there is anything left to read).
** 		- (0) if nothing left has to be read.
**
** ATTENTION :
** To prevent any memory leak, the user has to free the pointer from the call
** back function. The function does not free any memory before the memory
** allocation to the pointer.
*/

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	fill_buf(char *buf, char **line, int index)
{
	if (index >= 0)
	{
		*line = ft_strndup(buf, index + 1);
		ft_strcpy(buf, buf + index + 1);
	}
	else
	{
		*line = ft_strdup(buf);
		buf[0] = '\0';
	}
	return (index >= 0);
}

static int	concatenate(char *buf, char **line, int index)
{
	char *tmp;

	if (index >= 0)
		buf[index] = '\0';
	tmp = ft_strjoin(*line, buf);
	ft_memdel((void**)line);
	*line = tmp;
	if (index >= 0)
		ft_strcpy(buf, buf + index + 1);
	else
		buf[0] = '\0';
	return (1);
}

static int	ft_read(char *buf, char **line, int fd)
{
	int ret;
	int index;

	ret = read(fd, buf, BUFF_SIZE_GNL);
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (0);
	buf[ret] = '\0';
	index = ft_strindex(buf, '\n');
	concatenate(buf, line, index);
	if (index >= 0)
		return (1);
	else
		return (2);
}

int			get_next_line(int fd, char **line)
{
	static char		*fdtab[OPEN_MAX];
	int				ret;
	int				index;

	if (BUFF_SIZE_GNL <= 0 || fd < 0 || !line)
		return (-1);
	if (!fdtab[fd])
	{
		if (!(fdtab[fd] = (char *)malloc(sizeof(*(fdtab[fd]))
		* BUFF_SIZE_GNL + 1)))
			exit(EXIT_FAILURE);
		fdtab[fd][0] = 0;
	}
	index = ft_strindex(fdtab[fd], '\n');
	if (!(ret = fill_buf(fdtab[fd], line, index)))
		while ((ret = ft_read(fdtab[fd], line, fd)) > 1)
			;
	if (fdtab[fd][0] == 0)
		ft_memdel((void**)&fdtab[fd]);
	return (ret);
}
