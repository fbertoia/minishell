#include "minishell.h"

int ft_strindexstr(char *dest[NUMBER_BUILTIN], char *src)
{
	int i;
	
	i = 0;
	while (i < NUMBER_BUILTIN)
	{
		if (ft_strequ(dest[i], src))
			return (i);
		else
			i++;
	} 
	return (-1);
}
