#include "minishell.h"

int find_builtin(char *str)
{
	if (ft_strequ(str, "cd"))
		return (0);
	else if (ft_strequ(str, "echo"))
		return (1);
	else if (ft_strequ(str, "env"))
		return (2);
	else if (ft_strequ(str, "exit"))
		return (3);
	else if (ft_strequ(str, "setenv"))
		return (4);
	else if (ft_strequ(str, "unsetenv"))
		return (5);
	else
		return (-1);
}

int callfunction(char **args, t_data *data, t_env **env)
{
	static int (*ft_builtin[])(char **, t_env **, t_data *) =
	{&cd, &echo, &ft_env, &ft_exit, &ft_setenv, &ft_unsetenv};
	int i;

	i = 0;
	ft_printf("%[RED]Call function%[NC]\n");
	if ((i = find_builtin(args[0])) >= 0)
		return (ft_builtin[i](args, env, data));
	else
		return (data->i = callsystem(args, env, data));
}
