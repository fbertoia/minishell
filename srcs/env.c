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

int env(char *argv[], char *envp[], t_data *data)
{
	ft_printf("fonction env\n");
	return (1);
}
