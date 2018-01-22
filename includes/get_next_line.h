/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:48:26 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/30 21:16:40 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# define BUFF_SIZE_GNL 4028

int					get_next_line(const int fd, char **line, int i);

typedef struct		s_get
{
	char			content[BUFF_SIZE_GNL];
	struct s_get	*fd_ptr[OPEN_MAX];
	int				first;
	struct s_get	*next;
}					t_get;

#endif
