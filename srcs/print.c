/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:23:27 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/02 11:23:28 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(t_env *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	return (0);
}

void	print_arr_env(char **arr_env)
{
	ft_printf("%[RED]PRINT_ARR_ENV%[NC]\n");
	while (*arr_env)
	{
		ft_printf("%s\n", *arr_env);
		arr_env++;
	}
}

int	print_message(char *message, char *function_name)
{
	if (ft_strequ(message, "malloc"))
		ft_dprintf(2, "Malloc failure.\n");
	else if (ft_strequ(message, "ENAMETOOLONG"))
		ft_dprintf(2, "%s: Name exceeded PATH_MAX limit.\n", function_name);
	else if (ft_strequ(message, "EACCESS"))
		ft_dprintf(2, "%s: permission denied.\n", function_name);
	else if (ft_strequ(message, "EINVAL"))
		ft_dprintf(2, "%s: Invalid argument.\n", function_name);
	else if (ft_strequ(message, "ENOENT"))
		ft_dprintf(2, "%s: No such file or directory.\n", function_name);
	else if (ft_strequ(message, "ENOCMD"))
		ft_dprintf(2, "%s: Command not found.\n", function_name);
	else if (ft_strequ(message, "ENOMEN"))
		ft_dprintf(2, "%s: Insufficient memory.\n", function_name);
	else if (ft_strequ(message, "E2BIG"))
		ft_dprintf(2, "%s: Too many arguments.\n", function_name);
	return (1);
}
