/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:18:02 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 15:18:04 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		is_char(char to_compare, char c)
{
	if (c == to_compare)
		return (1);
	return (0);
}

static int		wordcount(char *str, char c)
{
	int ret;

	ret = 0;
	while (*str)
	{
		if (!is_char(*str, c))
		{
			ret++;
			while (*str && !is_char(*str, c))
				str++;
		}
		if (*str && is_char(*str, c))
			str++;
	}
	return (ret);
}

static int		size_word(char *str, char c)
{
	int ret;

	ret = 0;
	while (is_char(*str, c))
		str++;
	while (*str && !is_char(*str, c))
	{
		ret++;
		str++;
	}
	return (ret);
}

static void		copy(char *ret, char **str, char c)
{
	int i;

	i = 0;
	while (is_char(**str, c))
		(*str)++;
	while (**str && !is_char(**str, c))
	{
		ret[i] = **str;
		(*str)++;
		i++;
	}
	ret[i] = '\0';
}

char			**ft_strsplit(char *str, char c)
{
	int		nb_word;
	char	**arr;
	int		i;

	i = 0;
	nb_word = wordcount(str, c);
	if (!str)
		return (NULL);
	if ((arr = (char **)malloc(sizeof(char*) * (nb_word + 1))) == NULL)
		return (NULL);
	while (i < nb_word)
	{
		if ((arr[i] = (char*)malloc(sizeof(char) *
			(size_word(str, c) + 1))) == NULL)
			return (NULL);
		copy(arr[i], &str, c);
		i++;
	}
	arr[nb_word] = NULL;
	return (arr);
}
