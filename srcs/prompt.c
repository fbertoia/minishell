/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 21:24:28 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/03 21:24:30 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prompt(void)
{
	char buf[PATH_MAX + 1];

	getcwd(buf, PATH_MAX);
	if (ft_strnequ(buf, "/Users/fbertoia", 15))
	{
		ft_strcpy(buf + 1, buf + 15);
		buf[0] = '~';
	}
	if (!g_sig)
		ft_printf("%[5,162,103]%s ➜ %[NC]", buf);
	else
		ft_printf("%[162,0,0]%s ➜ %[NC]", buf);
	return (1);
}
