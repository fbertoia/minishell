/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:31:20 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/10 20:42:01 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_insert_spaces(char **str, t_p *box)
{
	if (box->flags & (1 << minus))
		box->flags &= ~(1 << zero);
	while (box->delta > 0)
	{
		(*str)[box->i] = (box->flags & (1 << zero)) ? '0' : ' ';
		box->delta -= 1;
		box->i += 1;
		box->ret += 1;
		ft_buffalloc(str, box, 1);
	}
}
