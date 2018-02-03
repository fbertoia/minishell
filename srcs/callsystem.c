#include "minishell.h"
#include <sys/wait.h>

int findpath(char *called_f, t_env *env, t_data *data)
{
	char **split_paths;
	int i = 0;
	t_env *tmp;

	tmp = elem_name(env, "PATH");
	split_paths = ft_strsplit(tmp ? tmp->value : "", ':');
	while (split_paths && split_paths[i])
	{
		if ((data->path = ft_strjoin_multiple(3, split_paths[i], "/", called_f)) == NULL)
			exit(EXIT_FAILURE);
		if (!lstat(data->path, data->buf) || errno != ENOENT)
			break;
		else
			ft_memdel((void**)&data->path);
		i++;
	}
	if (!data->path)
		data->path = ft_strdup(called_f);
	del_args(&split_paths);
	return (1);
}

int callsystem(char **av, t_env **env, t_data *data)
{
	if((data->parent = fork()) == -1)
	{
		perror("");
		return (1);
	}
	if (!data->parent)
	{
		findpath(av[0], data->env, data);
		g_sig = execve(data->path, av, copy_arr_env(data, *env));
		perror("");
		exit(EXIT_FAILURE);
	}
	else
	{
		data->parent = waitpid(data->parent, &(data->status), WUNTRACED);
		return (data->status);
	}
}
