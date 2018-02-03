/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 00:29:38 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 00:29:40 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env  *add_new_var2(char *environ)
{
	t_env *tmp;
	int i;

	i = ft_strindex(environ, '=');
	tmp = (t_env*)malloc(sizeof(t_env));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->value = ft_strdup(environ + i + 1);
	tmp->name = ft_strnew(i);
	tmp->next = NULL;
	ft_strlcat(tmp->name, environ, i + 1);
	return (tmp);
}

void	add_new_var(char *environ, t_data *data)
{
	t_env *tmp;
	t_env *queue;
	
	tmp = add_new_var2(environ);
	queue = data->env;
	tmp->next = queue;
	data->env = tmp;
}