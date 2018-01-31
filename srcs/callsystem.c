#include "minishell.h"
#include <sys/wait.h>

int findpath(char *called_f, char **env, t_data *data)
{
	char **split_paths;
	char *test_path;
	int i = 0;

	test_path = NULL;
	split_paths = NULL;
	setpath(env, &split_paths);
	while (split_paths[i])
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
	return (1);
}

int callsystem(char **av, char **env, t_data *data)
{
	if((data->parent = fork()) == -1)
	{
		perror("");
		return (1);
	}
	if (!data->parent)
	{
		findpath(data->split_args[0], env, data);
		g_sig = execve(data->path, av, env);
		perror("");
		exit(EXIT_FAILURE);
	}
	else
	{
		data->parent = waitpid(data->parent, &(data->status), WUNTRACED);
		ft_printf("data->status = %d\n", data->status);
		return (data->status);
	}
}
