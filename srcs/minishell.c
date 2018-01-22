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

int ft_strindexstr(char *dest[NUMBER_BUILTIN], char *src)
{
	int i;
	
	i = 0;
	while (i < NUMBER_BUILTIN)
	{
		if (ft_strequ(dest[i], src))
			return (i);
		else
			i++;
	} 
	return (-1);
}

void handlesig(int num)
{
	static int i = 0;
	
	printf("we caught that signal%d, i = %d\n", num, i);
	if (i > 10)
		exit(1);
	i++;
	// sig = 0;
}

int  main(int ac, char **av)
{
	t_data data;
	extern char **environ;

	data.i = 1;
	data.s = NULL;
	data.parent = 0;
	data.wait = NULL;
	copyenv(&data, environ);
	setpath(&data);
	while (42)
	{
		signal(SIGINT, handlesig);
		waitpid(0, data.wait, 0);
		signal(SIGINT, handlesig);
		prompt(&data);
		get_next_line(0, &data.s, 1);
		data.split_args = ft_strsplit(data.s, ' ');
		ft_memdel((void**)&data.s);
		data.i = callfunction(&data);
	}
}
