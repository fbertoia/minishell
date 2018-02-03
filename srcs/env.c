#include "minishell.h"

int print_usage_env(char c, int option)
{
	// if (option == 1)
	if (option == 2)
		ft_dprintf(2, "env: option requires an argument -- %c\n", c);
	ft_dprintf(2, "usage: env [-i] [-P utilpath] [-u name]\
[name=value ...] [utility [argument ...]]\n");
	return (1);
}

int ft_env(char *av[], t_env **env, t_data *data)
{
	int i;
	int a;

	i = 1;
	if (!av[i])
		return (print_env(*env));
	if (!data->copy_env)
		ft_copyenvlist(*env, &data->copy_env);
	if (av[i] && ft_strequ(av[i], "-i"))
	{
		delete_env(&data->copy_env);
		if (!av[++i])
			return (0);
	}
	if (av[i] && ft_strequ(av[i], "-P"))
	{
		if (av[++i])
		{
			if (!av[i])
				return (print_env(*env));
			if (data->path)
				ft_memdel((void**)&data->path);
			data->path = ft_strdup(av[i++]);
		}
		else
			return (print_usage_env('P', 2));
	}
	while (av[i] && ft_strequ(av[i], "-u"))
	{
		if (av[++i])
		{
			ft_unsetenv2(av[i++], &data->copy_env);
			if (!av[i])
				return (print_env(*env));
		}
		else
			return (print_usage_env('u', 2));
	}
	while (av[i] && (a = ft_strindex(av[i], '=')) >= 0)
	{
		if (av[i][0] == '=')
			return (print_message("EINVAL", av[0]));
		else
		{
			av[i][a] = '\0';
			ft_setenv2(av[i], av[i] + a + 1, &data->copy_env);
		}
		if (!av[++i])
			return (print_env(data->copy_env));
	}
	return (callfunction(av + i, data, &data->copy_env));
}
