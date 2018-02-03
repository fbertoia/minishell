/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 22:29:27 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 22:29:29 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	delete_envname(t_env *tmp)
{
	ft_memdel((void**)&tmp->name);
	ft_memdel((void**)&tmp->value);
	return (0);
}

int	ft_unsetenv2(char *av, t_env **env)
{
	t_env *tmp;
	t_env *tmp2;

	if (!(tmp = *env) || !av)
		return (0);
	if (ft_strequ(tmp->name, av))
	{
		*env = (*env)->next;
		delete_envname(tmp);
		ft_memdel((void**)&tmp);
		return (0);
	}
	while (tmp->next)
	{
		if (ft_strequ(tmp->next->name, av))
		{
			tmp2 = tmp->next;
			delete_envname(tmp2);
			tmp->next = tmp2->next;
			ft_memdel((void**)&tmp2);
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_unsetenv(char *av[], t_env **env, t_data *data)
{
	int ret;

	(void)data;
	ret = 0;
	av++;
	while (*av)
	{
		ret += ft_unsetenv2(*av, env);
		av++;
	}
	return (ret);
}
