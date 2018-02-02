#include "minishell.h"

int delete_envname(t_env *tmp)
{
	ft_memdel((void**)&tmp->name);
	ft_memdel((void**)&tmp->value);
}

int ft_unsetenv2(char *av, t_env **env)
{
	t_env *tmp;
	t_env *tmp2;

	ft_printf("av = %s\n", av);
	tmp = *env;
	if (!av || !*env)
		return (0);
	ft_printf("av = %s, *env = %s \n", av, tmp->name);
	if (ft_strequ(tmp->name, av))
	{
		*env = (*env)->next;
		delete_envname(tmp);
		ft_memdel((void**)&tmp);
		return (0);
	}
	while (tmp->next)
	{
		if (ft_strequ(tmp->next->name, av))
		{
			tmp2 = tmp->next;
			delete_envname(tmp2);
			tmp->next = tmp2->next;
			ft_memdel((void**)&tmp2);
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

int ft_unsetenv(char *av[], t_env **env, t_data *data)
{
	int ret;

	ret = 0;
	av++;
	while (*av)
	{
		ft_printf("av = %s\n", *av);
		ret += ft_unsetenv2(*av, env);
		av++;
	}
	return (ret);
}
