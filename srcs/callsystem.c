#include "minishell.h"

int findpath(char *called_f, char **env)
{
  char **split_paths;
  char *test_path;
  int i = 0;
  
  test_path = NULL;
  split_paths = NULL;
  split_paths = setpath(env, &split_paths);
  while (split_paths[i])
  {
    i++;
  }
}

int callsystem(char *argv[], char *envp[], t_data *data)
{
  int i;
  char **syscall_path;
  char *path_tocall;
  
  i = 0;
  data->parent = fork();
  if (findpath(data->split_args[0], data->path)
  if (!data->parent)
  {
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
