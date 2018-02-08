/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 22:29:50 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 22:29:53 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exit(char *argv[], t_env **env, t_data *data)
{
	(void)env;
	if (argv && argv[1])
		return (print_message("E2BIG", argv[0]));
	free_all(data);
	delete_env(&data->env);
	if (data->error == -1)
		exit(print_message("EBADF", "stdin"));
	exit(EXIT_SUCCESS);
}
