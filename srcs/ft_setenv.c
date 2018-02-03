#include "minishell.h"

int check_args(char **av)
{
	char *str;

	if (av[1] && av[2] && av[3])
		str = "setenv: Too many arguments.\n";
	else if (!str_alnum(av[1]))
		str = "setenv: Variable name must contain \
alphanumeric characters.\n";
	else if (!ft_isalpha(av[1][0]))
		str = "setenv: Variable name must begin with a letter.\n";
	else
		return (1);
	write(2, str, ft_strlen(str));
	return (0);
}

int ft_setenv2(char *name, char *value, t_env **env)
{
	t_env *tmp;
	t_env *new;

	if ((tmp = elem_name(*env, name)))
	{
		ft_memdel((void**)&tmp->value);
		tmp->value = ft_strdup(value ? value : "");
		return (0);
	}
	tmp = (t_env*)last_elem((t_void*)*env);
	new = new_env_var(name, value);
	if (!*env)
		*env = new;
	else
		tmp->next = new;
	return (0);
}

int ft_setenv(char *av[], t_env **env, t_data *data)
{
	if (!av[1])
		print_arr_env(data->arr_env);
	if (!check_args(av))
		return (1);
	return (ft_setenv2(av[1], av[2], env));
}
