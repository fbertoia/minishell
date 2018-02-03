/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 22:30:04 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 22:30:05 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char *argv[], t_env **env, t_data *data)
{
	int i;
	int flag;

	i = 1;
	flag = 1;
	(void)env;
	(void)data;
	if (ft_strequ(argv[1], "-n"))
	{
		i++;
		flag = 0;
	}
	while (argv[i])
	{
		if ((i > 1 && flag) || i > 2)
			ft_putchar(' ');
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (flag)
		ft_putchar('\n');
	return (0);
}
