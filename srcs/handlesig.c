#include "minishell.h"

void handlesig(int num)
{
	ft_printf("\n");
	sig = 0;
	prompt();
}