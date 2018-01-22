#include "minishell.h"

int copyenv(t_data *data, char **environ)
{
  int i;
  
  i = 0;
  while (environ[i])
    i++;
  data->env = (char**)malloc(sizeof(char*) * i);
  i--;
  while (i >= 0)
  {
    data->env[i] = ft_strdup(environ[i]);
    i--;
  }
  return (1);
}
