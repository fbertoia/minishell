#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <limits.h>
#include "libft.h"
#include "minishell.h"

int  main(int ac, char **av)
{
	int i;
	char *str;

	i = 0;
	str = ft_strjoin_multiple(3, "hey", "jude", "yes");
	printf("%s\n", str);
	free(str);
	// while(1);
	return (0);
}
