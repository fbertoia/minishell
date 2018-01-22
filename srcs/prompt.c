#include "minishell.h"

int prompt(void)
{
	if (sig)
		ft_printf("%[GRN]$>%[NC]");
	else
		ft_printf("%[RED]$>%[NC]");
}