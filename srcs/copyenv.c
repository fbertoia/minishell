#include "minishell.h"

char **copy_arr_env(t_data *data, t_env *env)
{
	t_env *tmp;
	int i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	data->arr_env = (char**)malloc(sizeof(char*) * (i + 1));
	tmp = env;
	i = 0;
	while (tmp)
	{
		if (!(data->arr_env[i++] = ft_strjoin_multiple(3, tmp->name, "=", tmp->value)))
			exit(EXIT_FAILURE);
		tmp = tmp->next;
	}
	data->arr_env[i] = NULL;
	return (data->arr_env);
}

t_env  *add_new_var2(char *environ)
{
	t_env *tmp;
	int i;

	i = ft_strindex(environ, '=');
	tmp = (t_env*)malloc(sizeof(t_env));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->value = ft_strdup(environ + i + 1);
	tmp->name = ft_strnew(i);
	tmp->next = NULL;
	ft_strlcat(tmp->name, environ, i + 1);
	return (tmp);
}

void	add_new_var(char *environ, t_data *data)
{
	t_env *tmp;
	t_env *queue;
	
	tmp = add_new_var2(environ);
	queue = data->env;
	tmp->next = queue;
	data->env = tmp;
}

int copyenv(t_data *data, char **environ)
{
	int i;

	data->env = NULL;
	i = 0;
	while (environ[i])
		i++;
	if (i > 0)
		i--;
	while (environ[i] && i >= 0)
	{
		add_new_var(environ[i], data);
		i--;
	}
	print_env(data->env);
	return (1);
}
