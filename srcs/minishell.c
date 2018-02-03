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
int g_prompt;

int  main(void)
{
	t_data data;
	extern char **environ;

	g_sig = 0;
	data.i = 1;
	data.s = NULL;
	data.wait = NULL;
	data.env = NULL;
	data.split_args = NULL;
	data.old_dir[0] = '\0';
	data.arr_env = NULL;
	data.copy_env = NULL;
	data.path = NULL;
	copyenv(&data, environ);
	signal(SIGINT, handlesig);
	while (42)
	{
		g_prompt = 1;
		data.parent = 0;
		prompt();
		get_next_line(0, &data.s);
		data.split_args = ft_strsplitwhitespace(data.s);
		ft_memdel((void**)&data.s);
		if (data.split_args && data.split_args[0])
		{
			g_prompt = 0;
			g_sig = callfunction(data.split_args, &data, &data.env);
		}
		del_args(&data.split_args);
		del_args(&data.arr_env);
		delstr(1, &data.path);
		delete_env(&data.copy_env);
		ft_memdel((void**)data.path);
	}
}

//recoder errno
