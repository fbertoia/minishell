#include "minishell.h"

void handlesig(int num)
{
	g_sig = 1;
	ft_printf("\n");
	if (g_prompt)
		prompt();
}