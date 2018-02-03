/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 00:49:50 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 00:49:51 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_var(t_env **env, char *name, char *value)
{
	t_env *tmp;
	t_env *needle;

	needle = *env;
	if ((tmp = elem_name(*env, name)))
	{
		ft_memdel((void**)&tmp->value);
		tmp->value = ft_strdup(value ? value : "");
	}
	else
	{
		tmp = new_env_var(name, value);
		needle = (t_env*)last_elem((void*)*env);
		if (needle)
			needle->next = tmp;
		else
			*env = tmp;
	}
	return (1);
}

