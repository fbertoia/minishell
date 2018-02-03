#include "minishell.h"

int cd_shortcuts(t_env **env, t_data *data, char *var)
{
	int i;
	t_env *tmp;

	tmp = elem_name(*env, var);
	if (tmp == NULL)
	{
		ft_dprintf(2, "%s not set\n", var);
		return (1);
	}
	i = chdir(tmp->value);
	if (i == -1)
		return (print_message("EACCESS", 2));
	change_var(env, "OLDPWD", data->old_dir);
	change_var(env, "PWD", getcwd(data->old_dir, PATH_MAX));
	return (0);
}

int checkargs_cd(char **argv)
{
	if (argv[1] && argv[2])
		print_message("too many args", 2);
	else if (argv[1] && ft_strlen(argv[1]) > PATH_MAX)
		print_message("ENAMETOOLONG", 2);
	else
		return (1);
	return (0);
}

int cd(char *argv[], t_env **env, t_data *data)
{
	t_env *tmp;
	int i;

	tmp = NULL;
	getcwd(data->old_dir, PATH_MAX);
	if (!checkargs_cd(argv))
		return (1);
	if (!argv[1] || (ft_strequ(argv[1], "~") && !argv[2]))
		return (cd_shortcuts(env, data, "HOME"));
	else if ((ft_strequ(argv[1], "-") || ft_strequ(argv[1], "--")) && !argv[2])
		return (cd_shortcuts(env, data, "OLDPWD"));
	else
		i = chdir(argv[1]);
	if (i == -1)
		return (print_message("EACCESS", 2));
	change_var(env, "OLDPWD", data->old_dir);
	change_var(env, "PWD", getcwd(data->old_dir, PATH_MAX));
	return (1);
}
