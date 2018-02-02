/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:26 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/02 20:08:29 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env *elem_name(t_env *env, char *str)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strequ(tmp->name, str))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env *new_env_var(char *name, char *value)
{
	t_env *tmp;

	tmp = (t_env*)malloc(sizeof(t_env));
	if (!tmp)
		exit (EXIT_FAILURE);
	tmp->next = 0;
	tmp->name = ft_strdup(name);
	if (*value)
		tmp->value = ft_strdup(value);
	else
		tmp->value = ft_strdup("");
	return (tmp);
}