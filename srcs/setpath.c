#include "minishell.h"

void setpath(char **env, char ***paths)
{
  int i;
  int j;
  
  i = 0;
  while ((j = ft_strnequ("PATH=", env[i], 5)))
    i++;
  if (j)
    *paths = ft_strsplit(env[i] + 6, ':');
  else
    *paths = NULL;
}
