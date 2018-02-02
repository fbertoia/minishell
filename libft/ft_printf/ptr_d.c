/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:08:10 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/11 20:08:12 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags_plus_minus_space(char **str, t_p *box, long long d)
{
	if (d < 0)
	{
		(*str)[box->i] = '-';
		box->i += 1;
		box->ret += 1;
	}
	else if (box->flags & (1 << plus) || box->flags & (1 << space))
	{
		(*str)[box->i] = (box->flags & (1 << plus)) ? '+' : ' ';
		box->i += 1;
		box->ret += 1;
	}
}

static void		ft_ltoa_insert_flags(char **str, t_p *box,
int len, long long d)
{
	if (box->flags & (1 << minus) || box->precision != -1)
		box->flags &= ~(1 << zero);
	if (box->flags & (1 << plus))
		box->flags &= ~(1 << space);
	if (box->flags & (1 << plus) || box->flags & (1 << space) || d < 0)
		box->width -= 1;
	box->precision -= len;
	box->delta = box->width - (box->precision > 0 ? box->precision : 0) -
	(box->tmp == 0 && d == 0 ? 0 : len);
	if (!(box->flags & (1 << minus)) && !(box->flags & (1 << zero)))
		ft_unsigned_insert_spaces(str, box);
	ft_flags_plus_minus_space(str, box, d);
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

int				ptr_d(char **str, va_list ap, t_p *box)
{
	long long	d;
	char		*tab;

	box->tmp = box->precision;
	if (box->converter == 'D')
		d = (long long)va_arg(ap, long);
	else
		d = ft_get_number(ap, box);
	tab = ft_lltoa(d, box);
	ft_ltoa_insert_flags(str, box, ft_strlen(tab), d);
	if ((box->tmp != 0 && d == 0) || d)
		ptr_copy(str, tab, box);
	if (box->delta)
		ft_unsigned_insert_spaces(str, box);
	free(tab);
	return (1);
}
