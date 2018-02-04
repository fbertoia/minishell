/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:49:55 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 20:50:35 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(char *str, size_t size)
{
	char *tmp;

	if (!str || size <= 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	ft_strlcpy(tmp, str, size);
	return (tmp);
}
