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

void	print_env(t_env *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
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

int	print_message(char *message, int fd)
{
	if (ft_strequ(message, "malloc"))
		ft_dprintf(fd, "Malloc failure.\n");
	if (ft_strequ(message, "too many args"))
		ft_dprintf(fd, "Too many arguments.\n");
	if (ft_strequ(message, "ENAMETOOLONG"))
		ft_dprintf(fd, "Name exceeded PATH_MAX limit.\n");
	if (ft_strequ(message, "EACCESS"))
		ft_dprintf(fd, "Read or search permission was denied for a component of\
the pathname.\n");
	return (1);
}