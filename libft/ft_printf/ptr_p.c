/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:22:48 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/11 16:22:50 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_insert_hexprime(char **str, t_p *box, int i)
{
	if (i >= 1)
	{
		(*str)[box->i] = '0';
		box->i += 1;
		box->ret += 1;
		(*str)[box->i] = 'x';
		box->i += 1;
		box->ret += 1;
		while (box->tmp > 0)
		{
			(*str)[box->i] = '0';
			box->i += 1;
			box->ret += 1;
			box->tmp -= 1;
			box->delta -= 1;
		}
	}
}

static void	ft_insert_hexsec(char **str, t_p *box, int i)
{
	if (i == 0)
	{
		(*str)[box->i] = '0';
		box->i += 1;
		box->ret += 1;
		(*str)[box->i] = 'x';
		box->i += 1;
		box->ret += 1;
		while (box->tmp > 0)
		{
			(*str)[box->i] = '0';
			box->i += 1;
			box->ret += 1;
			box->tmp -= 1;
			box->delta -= 1;
		}
	}
}

int			ptr_p(char **str, va_list ap, t_p *box)
{
	long	p;
	int		i;
	char	*tab;

	p = va_arg(ap, long);
	tab = ft_bouxtoa_base(p, box);
	i = ft_strlen(tab);
	box->tmp = (box->precision == -1 ? 0 : box->precision) - i;
	box->delta = box->width - ft_max(i, (box->precision == -1 ? 0 :
	box->precision)) - 2;
	ft_insert_hexprime(str, box, box->flags & (1 << zero));
	if (!(box->flags & (1 << minus)))
		ft_insert_spaces(str, box);
	ft_insert_hexsec(str, box, box->flags & (1 << zero));
	if (p || (!p && box->precision))
		ptr_copy(str, tab, box);
	if (box->width)
		ft_insert_spaces(str, box);
	free(tab);
	return (1);
}
