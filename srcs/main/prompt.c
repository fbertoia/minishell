/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 21:24:28 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 21:24:30 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void *not_for_use)
{
	static t_data	*data;
	t_env			*tmp;
	int				i;

	if (data == NULL)
	{
		data = (t_data*)not_for_use;
		return ;
	}
	getcwd(data->old_dir, PATH_MAX);
	tmp = elem_name(data->env, "HOME");
	if (tmp && *tmp->value)
	{
		i = ft_strlen(tmp->value);
		if (ft_strnequ(data->old_dir, tmp->value, i))
		{
			ft_strcpy(data->old_dir + 1, data->old_dir + i);
			data->old_dir[0] = '~';
		}
	}
	if (!g_sig)
		ft_printf("%[5,162,103]%s ➜ %[NC]", data->old_dir);
	else
		ft_printf("%[162,0,0]%s ➜ %[NC]", data->old_dir);
}
