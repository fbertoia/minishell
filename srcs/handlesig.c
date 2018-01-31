#include "minishell.h"

void handlesig(int num)
{
	// kill(0, SIGTERM);
	g_sig = 1;
	ft_printf("\n");
	prompt();
}