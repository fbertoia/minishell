/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_unsigned_commonbis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:23:03 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 17:58:24 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_insert_spaces(char **str, t_p *box)
{
	if (box->flags & (1 << minus))
		box->flags &= ~(1 << zero);
	while (box->delta > 0)
	{
		(*str)[box->i] = ' ';
		box->delta -= 1;
		box->i += 1;
		box->ret += 1;
		ft_buffalloc(str, box, 1);
	}
}

void	ptr_copy(char **str, char *tab, t_p *box)
{
	while (*tab)
	{
		(*str)[box->i] = *tab;
		box->i += 1;
		box->ret += 1;
		tab++;
	}
	ft_buffalloc(str, box, 1);
}
