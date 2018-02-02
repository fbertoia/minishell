/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:21:35 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/20 19:14:41 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 							FT_STRNINDEX
**
** Takes three arguments : the string and the decimal value of the character
** searched, and the maximum number of char to parse.
** Returns the index of the first character found into the string. Else, if
** if the character has not been found, the funcion returns (-1).
** In case a NULL string is sent in, (-1) is returned.
*/

#include "libft.h"

int		ft_strnindex(const char *str, int c, int n)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != c && i < n)
		i++;
	return (str[i] == c ? i : -1);
}
