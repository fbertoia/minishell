#include "minishell.h"

int ft_exit(char *argv[], t_env **env, t_data *data)
{
  del_args(&data->split_args);
  del_args(&data->arr_env);
  delete_env(&data->copy_env);
  ft_memdel((void**)data->path);
 	delete_env(&data->env);
  exit(EXIT_SUCCESS);
}
