#include "minishell.h"

void handlesig(int num)
{
	g_sig = 1;
	if (g_prompt)
	{
		ft_printf("\n");
		prompt();
	}
}