#include "minishell.h"

void del_args(char ***args)
{
  int i;

  i = 0;
  if (!*args)
  	return ;
  while ((*args)[i])
  {
    ft_memdel((void**)&(*args)[i]);
    i++;
  }
  ft_memdel((void**)&(*args));
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

void delete_env(t_env **env)
{
  t_env *tmp;

  tmp = *env;
  while (*env)
  {
    *env = (*env)->next;
    ft_memdel((void**)&tmp->name);
    ft_memdel((void**)&tmp->value);
    ft_memdel((void**)&tmp);
    tmp = *env;
  }
}