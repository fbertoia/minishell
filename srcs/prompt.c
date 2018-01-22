#include "minishell.h"

int prompt(t_data *data)
{
	if (sig)
		ft_printf("%[GRN]$>%[NC]");
	else
		ft_printf("%[RED]$>%[NC]");
}