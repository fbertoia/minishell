#include "minishell.h"

void setpath(t_data *data)
{
  int i;
  int j;
  
  i = 0;
  while ((j = ft_strnequ("PATH=", data->env[i], 5)))
    i++;
  if (j)
    data->path = ft_strsplit(data->env[i] + 6, ':');
  else
    data->path = NULL;
}
