/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:35:25 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/12 23:35:27 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_otoa_insert_flags(char **str, t_p *box,
		int len, unsigned long long o)
{
	ft_flag_reorganize(box);
	if (box->precision > 0)
		box->flags &= ~(1 << hashtag);
	box->precision -= (len);
	box->delta = box->width - ft_max(box->phold, o ||
	box->phold != 0 ? len : 0);
	box->delta -= ((box->flags & (1 << hashtag) && (o || (box->tmp))) ? 1 : 0);
	if (!(box->flags & (1 << minus)) && !(box->flags & (1 << zero)))
		ft_unsigned_insert_spaces(str, box);
	ft_hashtag_box(str, box, o);
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

int			ptr_o(char **str, va_list ap, t_p *box)
{
	unsigned long long	o;
	char				*tab;

	box->tmp = ((box->precision == 0) ? 1 : 0);
	box->phold = box->precision;
	if (box->converter == 'O')
		o = (unsigned long long)va_arg(ap, unsigned long);
	else
		o = ft_boux_get_number(ap, box);
	tab = ft_bouxtoa_base(o, box);
	ft_otoa_insert_flags(str, box, ft_strlen(tab), o);
	if (box->phold != 0 || o)
		ptr_copy(str, tab, box);
	if (box->delta)
		ft_unsigned_insert_spaces(str, box);
	free(tab);
	return (1);
}
