/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:22:14 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/12 17:22:18 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ultoa_insert_flags(char **str, t_p *box, int len)
{
	ft_flag_reorganize(box);
	box->precision -= len;
	box->delta = box->width - (box->precision > 0 ? box->precision : 0) - len;
	if (!(box->flags & (1 << minus)) && !(box->flags & (1 << zero)))
		ft_unsigned_insert_spaces(str, box);
	while (box->precision > 0 || (box->flags & (1 << zero) ?
	box->delta > 0 : 0))
	{
		(*str)[box->i] = '0';
		box->precision -= 1;
		box->delta -= box->flags & (1 << zero) ? 1 : 0;
		box->i += 1;
		box->ret += 1;
		ft_buffalloc(str, box, 1);
	}
}

int			ptr_u(char **str, va_list ap, t_p *box)
{
	unsigned long long	u;
	char				*tab;
	int					flag;

	if (box->converter == 'U')
		u = (unsigned long long)va_arg(ap, unsigned long);
	else
		u = ft_boux_get_number(ap, box);
	flag = (u == 0 && box->precision == 0 ? 0 : 1);
	tab = ft_bouxtoa_base(u, box);
	ft_ultoa_insert_flags(str, box, ft_strlen(tab));
	if (flag)
		ptr_copy(str, tab, box);
	if (box->delta)
		ft_unsigned_insert_spaces(str, box);
	free(tab);
	return (1);
}
