/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_shlvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:32:53 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/05 20:32:55 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increase_shlvl(t_env *env)
{
	t_env	*tmp;
	char	*str;

	tmp = elem_name(env, "SHLVL");
	if (!tmp)
		return ;
	str = tmp->value;
	tmp->value = ft_itoa(ft_atoi(tmp->value) + 1);
	ft_memdel((void**)&str);
}
