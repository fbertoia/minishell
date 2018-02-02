/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:53:00 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/07 18:53:01 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ptr_pct(char **str, va_list ap, t_p *box)
{
	(void)ap;
	box->delta = box->width - 1;
	if (!(box->flags & (1 << minus)))
		ft_insert_spaces(str, box);
	(box->ret) += 1;
	(*str)[box->i] = '%';
	box->i += 1;
	if (box->width)
		ft_insert_spaces(str, box);
	return (1);
}
