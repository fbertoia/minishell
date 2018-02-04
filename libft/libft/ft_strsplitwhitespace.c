/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwhitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:06:47 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/31 16:10:37 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

static int		wordcount(char *str)
{
	int ret;

	ret = 0;
	while (*str)
	{
		if (!is_whitespace(*str))
		{
			ret++;
			while (*str && !is_whitespace(*str))
				str++;
		}
		if (*str && is_whitespace(*str))
			str++;
	}
	return (ret);
}

static int		size_word(char *str)
{
	int ret;

	ret = 0;
	while (is_whitespace(*str))
		str++;
	while (*str && !is_whitespace(*str))
	{
		ret++;
		str++;
	}
	return (ret);
}

static void		copy(char *ret, char **str)
{
	int i;

	i = 0;
	while (is_whitespace(**str))
		(*str)++;
	while (**str && !is_whitespace(**str))
	{
		ret[i] = **str;
		(*str)++;
		i++;
	}
	ret[i] = '\0';
}

char			**ft_strsplitwhitespace(char *str)
{
	int		nb_word;
	char	**arr;
	int		i;

	i = 0;
	nb_word = wordcount(str);
	if (!str)
		return (NULL);
	if ((arr = (char **)malloc(sizeof(char*) * (nb_word + 1))) == NULL)
		return (NULL);
	while (i < nb_word)
	{
		if ((arr[i] = (char*)malloc(sizeof(char) *
			(size_word(str) + 1))) == NULL)
			return (NULL);
		copy(arr[i], &str);
		i++;
	}
	arr[nb_word] = NULL;
	return (arr);
}
