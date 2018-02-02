#include "minishell.h"

int echo(char *argv[], t_env **env, t_data *data)
{
	int i;
	int flag;

	i = 1;
	flag = 1;
	if (ft_strequ(argv[1], "-n"))
	{
		i++;
		flag = 0;
	}
	while (argv[i])
	{
		if ((i > 1 && flag) || i > 2)
			ft_putchar(' ');		
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (flag)
		ft_putchar('\n');
	return (0);
}
