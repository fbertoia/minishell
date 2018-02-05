/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callsystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 22:30:37 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 22:30:39 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

static int		finderror(char *function_name, struct stat *buf, int ret)
{
	if (ret)
	{
		if (ft_strindex(function_name, '/') == -1)
			exit(print_message("ENOCMD", function_name));
		exit(print_message("ENOENT", function_name));
	}
	if (!(!ret && buf->st_mode & S_IXUSR))
		exit(print_message("EACCESS", function_name));
	return (1);
}

static void		findpath2(char *called_f, t_data *data,
struct stat *buf, int *j)
{
	data->path = ft_strdup(called_f);
	*j = lstat(data->path, buf);
}

static int		findpath(char *called_f, t_env *env,
t_data *data, struct stat *buf)
{
	char	**split_paths;
	int		i;
	int		j;
	t_env	*tmp;

	i = 0;
	tmp = elem_name(env, "PATH");
	split_paths = ft_strsplit(tmp ? tmp->value : "", ':');
	while (split_paths && split_paths[i])
	{
		if ((data->path = ft_strjoin_multiple(3, split_paths[i],
		"/", called_f)) == NULL)
			exit(EXIT_FAILURE);
		if (!(j = lstat(data->path, buf)))
			break ;
		else
			ft_memdel((void**)&data->path);
		i++;
	}
	if (!data->path)
		findpath2(called_f, data, buf, &j);
	del_args(&split_paths);
	return (j);
}

static int		add_functionname_topath(char **av, t_data *data,
struct stat *buf)
{
	char *tmp;

	tmp = ft_strjoin_multiple(3, data->path, "/", av[0]);
	ft_memdel((void**)&data->path);
	data->path = tmp;
	return (lstat(data->path, buf));
}

int				callsystem(char **av, t_env **env, t_data *data)
{
	struct stat	buf;
	int			lstat;

	if ((data->parent = fork()) == -1)
	{
		print_message("ENOMEN", av[0]);
		return (1);
	}
	if (!data->parent)
	{
		if (!data->path)
			lstat = findpath(av[0], data->env, data, &buf);
		else
			lstat = add_functionname_topath(av, data, &buf);
		finderror(av[0], &buf, lstat);
		g_sig = execve(data->path, av, copy_arr_env(data, *env));
		exit(print_message("EACCESS", av[0]));
	}
	else
	{
		data->parent = waitpid(data->parent, &(data->status), WUNTRACED);
		return (data->status);
	}
}
