/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:46:18 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/19 10:28:50 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	ft_sortstrings(char **ptr, size_t size, int (*f)(char *, char *))
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if (!f(ptr[i], ptr[i + 1]))
		{
			tmp = ptr[i + 1];
			ptr[i + 1] = ptr[i];
			ptr[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
