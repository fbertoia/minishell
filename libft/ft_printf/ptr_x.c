/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:20:07 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/12 17:20:11 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xtoa_insert_spaces(char **str, t_p *box)
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

void	ft_bxtoa_insert_flags(char **str, t_p *box, int len,
		unsigned long long x)
{
	ft_flag_reorganize(box);
	box->precision -= len;
	box->delta = box->width - (box->precision > 0 ? box->precision : 0) -
	(x == 0 && box->precision + len == 0 ? 0 : len);
	box->delta -= ((box->flags & (1 << hashtag)) && x ? 2 : 0);
	if (!(box->flags & (1 << minus)) && !(box->flags & (1 << zero)))
		ft_xtoa_insert_spaces(str, box);
	ft_hashtag_box(str, box, x);
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

int		ptr_x(char **str, va_list ap, t_p *box)
{
	unsigned long long	x;
	char				*tab;
	int					flag;

	box->tmp = ((box->precision == -1 || box->precision == 1) ? 0 : 1);
	x = ft_boux_get_number(ap, box);
	flag = (x == 0 && box->precision == 0 ? 0 : 1);
	tab = ft_bouxtoa_base(x, box);
	ft_bxtoa_insert_flags(str, box, ft_strlen(tab), x);
	if (flag)
		ptr_copy(str, tab, box);
	if (box->delta)
		ft_unsigned_insert_spaces(str, box);
	free(tab);
	return (1);
}
