#include "minishell.h"

char *get_envvar(char **env, char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	while (env[i])
	{
		if (ft_strnequ(env[i], str, len))
			return (ft_strdup(env[i] + len));
		i++;
	}
	return (NULL);
}

int ft_env(char *av[], t_env **env, t_data *data)
{
	if (!av[1])
	{
		print_env(*env);
		return (0);
	}
	
	return (0);
}
