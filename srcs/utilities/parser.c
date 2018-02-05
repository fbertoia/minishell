/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:24:02 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/05 22:24:04 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*quotes_parser(char *tmp, char c, int *i, t_data *data)
{
	int		j;
	char	*ret;

	j = 1;
	while (tmp[j] && tmp[j] != c)
		j++;
	if (!tmp[j])
		data->quotes = (c == '\'' ? 1 : 2);
	ret = ft_strndup(tmp + 1, j);
	if (ret == NULL)
		exit(print_message("malloc", ""));
	*i += j + (tmp[j] ? 1 : 0);
	return (ret);
}

static char		*char_parser(char *tmp, int *i)
{
	int		j;
	char	*ret;

	j = 0;
	while (tmp[j] && tmp[j] != ' ' && tmp[j] != '\t' && tmp[j] != '\v')
		j++;
	ret = ft_strndup(tmp, j + 1);
	if (ret == NULL)
		exit(print_message("malloc", ""));
	*i += j;
	return (ret);
}

static t_parser	*parser2(char *str, int *i, t_data *data)
{
	char		*tmp;
	t_parser	*ret;

	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\v'))
		*i += 1;
	if (str[*i] == '\"' || str[*i] == '\'' || str[*i])
	{
		tmp = str + *i;
		ret = (t_parser*)malloc(sizeof(t_parser));
		if (ret == NULL)
			exit(print_message("malloc", ""));
		ret->arg = (str[*i] == '\"' || str[*i] == '\''
					? quotes_parser(tmp, str[*i], i, data)
					: char_parser(tmp, i));
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}

static void		build_args(t_data *data, t_parser *parser, int size)
{
	int i;

	i = 0;
	data->split_args = (char**)malloc(sizeof(char*) * (size + 1));
	if (data->split_args == NULL)
		exit(print_message("malloc", ""));
	while (i < size)
	{
		ft_printf("%[RED]BUILDER 2%[NC] Arg to print = |%s|\n", parser->arg);
		data->split_args[i] = ft_strdup(parser->arg);
		i++;
		parser = parser->next;
	}
	data->split_args[i] = NULL;
}

int				parser(t_data *data)
{
	t_parser	*tmp;
	int			i;

	i = 0;
	data->parser = parser2(data->s, &i, data);
	tmp = data->parser;
	while (data->s[i])
	{
		tmp->next = parser2(data->s, &i, data);
		if (tmp->next)
			tmp = tmp->next;
	}
	if (data->quotes > 0)
	{
		ft_dprintf(2, "One [%c] is missing.\n", data->quotes == 1
		? '\'' : '\"');
		return (1);
	}
	build_args(data, data->parser, size_list(data->parser));
	return (0);
}
