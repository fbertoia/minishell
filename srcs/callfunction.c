#include "minishell.h"

int callfunction(t_data *data)
{
  static int (*ft_builtin[])(char **, char **, t_data *) =
    {&cd, &echo, &env, &ft_exit, &ft_setenv, &ft_unsetenv};
  static char *builtin[NUMBER_BUILTIN] =
    {"cd", "echo", "env", "exit", "setenv", "unsetenv"};

  if ((data->i = ft_strindexstr(builtin, data->split_args[0])) >= 0)
    return(ft_builtin[data->i](data->split_args + 1, data->env, data));
  else
  {
    // ft_printf("i = %d\n", data->i);
    data->i = callsystem(data->split_args + 1, data->env, data);
  }
  return (1);
}
