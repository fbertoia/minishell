/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 22:30:15 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 22:30:16 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*copy_elem(t_env *src)
{
	t_env *tmp;

	tmp = (t_env*)malloc(sizeof(t_env));
	if (!tmp)
		exit(EXIT_FAILURE);
	tmp->next = NULL;
	tmp->name = ft_strdup(src->name);
	tmp->value = ft_strdup(src->value);
	return (tmp);
}

int		ft_copyenvlist(t_env *src, t_env **copy_env)
{
	t_env *tmp;

	if (!src)
		return (1);
	*copy_env = copy_elem(src);
	tmp = *copy_env;
	src = src->next;
	while (src)
	{
		tmp->next = copy_elem(src);
		tmp = tmp->next;
		src = src->next;
	}
	return (1);
}

char	**copy_arr_env(t_data *data, t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	data->arr_env = (char**)malloc(sizeof(char*) * (i + 1));
	tmp = env;
	i = 0;
	while (tmp)
	{
		if (!(data->arr_env[i++] = ft_strjoin_multiple(3,
		tmp->name, "=", tmp->value)))
			exit(EXIT_FAILURE);
		tmp = tmp->next;
	}
	data->arr_env[i] = NULL;
	return (data->arr_env);
}

int		copyenv(t_data *data, char **environ)
{
	int i;

	data->env = NULL;
	i = 0;
	while (environ[i])
		i++;
	if (i > 0)
		i--;
	while (environ[i] && i >= 0)
	{
		add_new_var(environ[i], data);
		i--;
	}
	return (1);
}
