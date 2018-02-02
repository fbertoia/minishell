/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:18:56 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/10 20:18:58 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_c_case(char **str, char c, t_p *box)
{
	(*str)[box->i] = c;
	box->i += 1;
	box->ret += 1;
	ft_buffalloc(str, box, 1);
}

int		ptr_c(char **str, va_list ap, t_p *box)
{
	char c;

	if (((box->modifier & (1 << ell))))
		return (ptr_cmaj(str, ap, box));
	c = (char)va_arg(ap, int);
	box->delta = box->width - 1;
	if (!(box->flags & (1 << minus)))
		ft_insert_spaces(str, box);
	ptr_c_case(str, c, box);
	if (box->width)
		ft_insert_spaces(str, box);
	return (1);
}
