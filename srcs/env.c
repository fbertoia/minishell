/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 21:25:53 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 21:37:13 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	flag_i(char **av, t_data *data, int *i)
{
	delete_env(&data->copy_env);
	if (!av[++(*i)])
		return (0);
	return (2);
}

static int	flag_p(char **av, t_env **env, t_data *data, int *i)
{
	if (av[++(*i)])
	{
		if (!av[*i])
			return (print_env(*env));
		if (data->path)
			ft_memdel((void**)&data->path);
		data->path = ft_strdup(av[(*i)++]);
	}
	else
		return (print_usage_env('P', 2));
	return (2);
}

static int	flag_u(char **av, t_env **env, t_data *data, int *i)
{
	if (av[++(*i)])
	{
		ft_unsetenv2(av[(*i)++], &data->copy_env);
		if (!av[*i])
			return (print_env(*env));
	}
	else
		return (print_usage_env('u', 2));
	return (2);
}

static int	flag_equal(char **av, t_data *data, int *i)
{
	int a;

	a = ft_strindex(av[*i], '=');
	if (av[*i][0] == '=')
		return (print_message("EINVAL", av[0]));
	else
	{
		av[*i][a] = '\0';
		ft_setenv2(av[*i], av[*i] + a + 1, &data->copy_env);
	}
	if (!av[++(*i)])
		return (print_env(data->copy_env));
	return (2);
}

int			ft_env(char *av[], t_env **env, t_data *data)
{
	int i;
	int ret;

	i = 1;
	if (!av[i])
		return (print_env(*env));
	if (!data->copy_env)
		ft_copyenvlist(*env, &data->copy_env);
	if (av[i] && ft_strequ(av[i], "-i"))
		if ((ret = flag_i(av, data, &i)) < 2)
			return (ret);
	if (av[i] && ft_strequ(av[i], "-P"))
		if ((ret = flag_p(av, env, data, &i)) < 2)
			return (ret);
	while (av[i] && ft_strequ(av[i], "-u"))
		if ((ret = flag_u(av, env, data, &i)) < 2)
			return (ret);
	while (av[i] && (ft_strindex(av[i], '=')) >= 0)
		if ((ret = flag_equal(av, data, &i)) < 2)
			return (ret);
	return (callfunction(av + i, data, &data->copy_env));
}
