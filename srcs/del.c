/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 21:22:35 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 21:22:37 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_args(char ***args)
{
	int i;

	i = 0;
	if (!*args)
		return ;
	while ((*args)[i])
	{
		ft_memdel((void**)&(*args)[i]);
		i++;
	}
	ft_memdel((void**)&(*args));
}

void	delstr(int nb_args, ...)
{
	va_list	ap;
	int		i;
	char	**tmp;

	i = 0;
	va_start(ap, nb_args);
	while (i < nb_args)
	{
		tmp = va_arg(ap, char **);
		ft_memdel((void**)tmp);
		i++;
	}
	va_end(ap);
}

void	delete_env(t_env **env)
{
	t_env *tmp;

	tmp = *env;
	while (*env)
	{
		*env = (*env)->next;
		ft_memdel((void**)&tmp->name);
		ft_memdel((void**)&tmp->value);
		ft_memdel((void**)&tmp);
		tmp = *env;
	}
}

void	free_all(t_data *data)
{
	del_args(&data->split_args);
	del_args(&data->arr_env);
	delstr(1, &data->path);
	delete_env(&data->copy_env);
}
