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

int callfunction(t_data *data)
{
  static int (*ft_builtin[])(char **, char **, t_data *) =
  {&cd, &echo, &env, &ft_exit, &ft_setenv, &ft_unsetenv};
  int i;

  i = 0;
  if ((i = find_builtin(data->split_args[0])) >= 0)
    return (ft_builtin[i](data->split_args, data->env, data));
  else
    return (data->i = callsystem(data->split_args, data->env, data));
}
