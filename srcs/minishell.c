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

int sig;

int  main(int ac, char **av)
{
	t_data data;
	extern char **environ;

	sig = 1;
	data.i = 1;
	data.s = NULL;
	data.parent = 0;
	data.wait = NULL;
	data.env = NULL;
	copyenv(&data, environ);
	while (42)
	{
		waitpid(0, data.wait, 0);
		signal(SIGINT, handlesig);
		prompt();
		get_next_line(0, &data.s, 1);
		data.split_args = ft_strsplit(data.s, ' ');
		ft_memdel((void**)&data.s);
		sig = callfunction(&data);
	}
}
