#include "minishell.h"
#include <sys/wait.h>

int finderror(char *function_name, struct stat *buf, t_data *data, int ret)
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

int findpath(char *called_f, t_env *env, t_data *data, struct stat *buf)
{
	char **split_paths;
	int i = 0;
	int j;
	t_env *tmp;

	tmp = elem_name(env, "PATH");
	split_paths = ft_strsplit(tmp ? tmp->value : "", ':');
	while (split_paths && split_paths[i])
	{
		if ((data->path = ft_strjoin_multiple(3, split_paths[i], "/", called_f)) == NULL)
			exit(EXIT_FAILURE);
		if (!(j = lstat(data->path, buf)))
			break;
		else
			ft_memdel((void**)&data->path);
		i++;
	}
	if (!data->path)
	{
		data->path = ft_strdup(called_f);
		j = lstat(data->path, buf);
	}
	del_args(&split_paths);
	return (j);
}

int add_functionname_topath(char **av, t_data *data, struct stat *buf)
{
	char *tmp;

	tmp = ft_strjoin_multiple(3, data->path, "/", av[0]);
	ft_memdel((void**)&data->path);
	data->path = tmp;
	return (lstat(data->path, buf));
}

int callsystem(char **av, t_env **env, t_data *data)
{
	struct stat buf;
	int lstat;

	if((data->parent = fork()) == -1)
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
		finderror(av[0], &buf, data, lstat);
		g_sig = execve(data->path, av, copy_arr_env(data, *env));
		exit(print_message("EACCESS", av[0]));
	}
	else
	{
		data->parent = waitpid(data->parent, &(data->status), WUNTRACED);
		return (data->status);
	}
}
