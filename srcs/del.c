#include "minishell.h"

void del_args(char ***args)
{
  int i;

  i = 0;
  if (!*args)
  	return ;
  while ((*args)[i])
  {
    free((*args)[i]);
    i++;
  }
  free(*args);
}

void delstr(int nb_args, ...)
{
  va_list ap;
  int i;
  char *tmp;

  i = 0;
  va_start(ap, nb_args);
  while (i < nb_args)
  {
    tmp = va_arg(ap, char *);
    ft_memdel((void**)&tmp);
    i++;
  }
  va_end(ap);
}
