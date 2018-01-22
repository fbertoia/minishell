#include "minishell.h"

int callsystem(char *argv[], char *envp[], t_data *data)
{
  int i;
  
  i = 0;
  data->parent = fork();
  if (!data->parent)
  {
    ft_printf("inside it");
    while (data->path[i])
    {
      data->split_args += 1;
      sig = execve(data->path[i], data->split_args, envp);
      i++;
    }
    return (0);
  }
  else
    return (1);
}
