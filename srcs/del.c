#include "minishell.h"

void del_arrstr(char ***arr)
{
  int i;
  
  i = 0;
  while ((*arr)[i])
  {
    ft_memdel((void**)&((*arr)[i]));
    i++;
  }
  ft_memdel((void**)*arr);
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
