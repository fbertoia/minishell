#include "minishell.h"

int		str_alnum(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int check_args(char **av)
{
	char *str;

	if (av[1] && av[2] && av[3])
		str = "setenv: Too many arguments.";
	else if (!str_alnum(av[1]) || !str_alnum(av[2]))
		str = "setenv: Variable name must contain \
alphanumeric characters.";
	else if (!ft_isalpha(av[1][0]) || (av[1] && av[2] && !ft_isalpha(av[2][0])))
		str = "setenv: Variable name must begin with a letter.";
	else
		return (1);
	write(2, str, ft_strlen(str));
	return (0);
}


int ft_setenv(char *av[], t_env **env, t_data *data)
{
	t_env *tmp;
	t_env *new;

	if (!av[1])
		print_arr_env(data->arr_env);
	if (!check_args(av))
		return (1);
	if ((tmp = elem_name(*env, av[1])))
	{
		ft_memdel((void**)&tmp->value);
		tmp->value = ft_strdup(av[2] ? av[2] : "");
		return (0);
	}
	tmp = (t_env*)last_elem((t_void*)data->env);
	new = new_env_var(av[1], av[2]);
	if (!data->env)
		data->env = new;
	else
		tmp->next = new;
	return (0);
}
