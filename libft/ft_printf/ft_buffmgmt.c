/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:08:10 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 03:33:46 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_write(char **ptr, t_p *box, int type)
{
	if (box->i >= BUFF_SIZE || type == 2)
	{
		write(box->fd, *ptr, box->i);
		box->i = 0;
	}
}

void				ft_buffalloc(char **ptr, t_p *box, int type)
{
	if (*ptr == NULL)
	{
		if (!(*ptr = (char *)malloc(sizeof(char) *
		(BUFF_SIZE + BUFF_SIZE_ERROR))))
			exit(EXIT_FAILURE);
		**ptr = 0;
	}
	ft_write(ptr, box, type);
	if (type == 2)
	{
		free(*ptr);
		return ;
	}
}
