/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:16:42 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/13 23:16:44 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ptr_b(char **str, va_list ap, t_p *box)
{
	unsigned long long	b;
	char				*tab;
	int					flag;

	box->tmp = ((box->precision == -1 || box->precision == 1) ? 0 : 1);
	b = ft_boux_get_number(ap, box);
	flag = (b == 0 && box->precision == 0 ? 0 : 1);
	tab = ft_bouxtoa_base(b, box);
	ft_bxtoa_insert_flags(str, box, ft_strlen(tab), b);
	if (flag)
		ptr_copy(str, tab, box);
	if (box->delta)
		ft_xtoa_insert_spaces(str, box);
	free(tab);
	return (1);
}
