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
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_strjoin_beta(char **s1, char *s2, int j)
{
	char	*ret;
	int		i;
	int		k;

	k = ft_strlen(s2);
	if (!s2)
		return (-1);
	i = ft_strlen(*s1);
	if ((ret = (char *)malloc(sizeof(char) * ((i == -1 ? 0 : i) +
	(j == -1 ? k : j) + 1))) == NULL)
		return (-1);
	i = 0;
	while (*s1 && (*s1)[i])
	{
		ret[i] = (*s1)[i];
		i++;
	}
	while (s2 && *s2 && *s2 != '\n')
		ret[i++] = *(s2++);
	ret[i] = 0;
	if (*s1)
		free(*s1);
	*s1 = ret;
	return (k);
}

char	*ft_strcpy_beta(char *dst, const char *src, int move)
{
	int i;
	int j;

	i = 0;
	j = 0;
	src += move;
	while (src[i])
	{
		dst[i] = src[i];
		j = 1;
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

int		ft_read(char **fdtab, char **line, int fd, int type)
{
	int a;
	int b;

	if (type)
	{
		if ((a = ft_strindex(*fdtab, '\n')) != -1 || **fdtab || (type & 2))
		{
			b = ft_strjoin_beta(line, *fdtab, a);
			ft_strcpy_beta(*fdtab, *fdtab, (a != -1 ? a + 1 :
			ft_strindex(*fdtab, 0)));
			if (type & 2)
				return (b == -1 ? -1 : b);
			return (a != -1 ? b : ft_read(fdtab, line, fd, 0));
		}
		else
			return (ft_read(fdtab, line, fd, 0));
	}
	else
	{
		if ((a = read(fd, *fdtab, BUFF_SIZE_GNL)) == -1)
			return (-1);
		(*fdtab)[a] = 0;
		return (ft_read(fdtab, line, fd, 1));
	}
}

int		get_next_line(const int fd, char **line)
{
	static char		*fdtab[OPEN_MAX] = {0};
	int				tmp;

	if (BUFF_SIZE_GNL <= 0 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!fdtab[fd])
	{
		if (!(fdtab[fd] = (char *)malloc(sizeof(*(fdtab[fd]))
		* BUFF_SIZE_GNL + 1)))
			return (-1);
		fdtab[fd][0] = 0;
	}
	tmp = ft_read(&fdtab[fd], line, fd, 1);
	if (tmp == -1)
		return (-1);
	if (fdtab[fd][0] == 0)
		ft_memdel((void**)&fdtab[fd]);
	if (!fdtab[fd] && (!(*line) || !**line) && !tmp)
		return (0);
	else
		return (1);
}
