/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <fbertoia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:39:25 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/22 02:13:16 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_sig;

int  main(int ac, char **av)
{
	t_data data;
	extern char **environ;

	g_sig = 0;
	data.i = 1;
	data.s = NULL;
	data.wait = NULL;
	data.env = NULL;
	data.split_args = NULL;
	data->old_dir[0] = '\0';
	copyenv(&data, environ);
	while (42)
	{
		data.parent = 0;
		prompt();
		signal(SIGINT, handlesig);
		get_next_line(0, &data.s);
		data.split_args = ft_strsplitwhitespace(data.s);
		ft_memdel((void**)&data.s);
		if (data.split_args && data.split_args[0])
			g_sig = callfunction(&data);
		del_args(&data.split_args);
	}
}
