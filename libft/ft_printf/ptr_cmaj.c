/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_cmaj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:25:33 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/10 21:49:15 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	subfunct(char **str, t_p *box, int i, unsigned char mask)
{
	if (!i || MB_CUR_MAX == 1)
		ptr_c_case(str, (char)box->c, box);
	else
	{
		mask |= (0xff & (box->c >> ((i / 6) * 6)));
		while (i % 6)
		{
			(*str)[box->i] = mask;
			box->i += 1;
			box->ret += 1;
			mask = 0x80;
			i -= 5;
			mask |= (0x3f & (box->c >> ((i % 6 == 0 ? 0 : i / 6) * 6)));
		}
		(*str)[box->i] = mask;
		box->i += 1;
		box->ret += 1;
	}
}

int		error_case(t_p *box)
{
	int i;

	i = 1;
	if (box->c < 0x80 || MB_CUR_MAX == 1)
		i = 1;
	else if (box->c < 0x800)
		i = 2;
	else if (box->c < 0x10000)
		i = 3;
	else if (box->c < 0x200000)
		i = 4;
	if ((MB_CUR_MAX == 1 && box->c >= 0x100) || (MB_CUR_MAX == 2 &&
	box->c >= 0x800) || (MB_CUR_MAX == 3 && box->c >= 0x10000) ||
	(MB_CUR_MAX == 4 && box->c >= 0x200000) || (box->c >= 0xd800 &&
	box->c <= 0xdfff) || box->c >= 0x10ffff || box->c < 0)
	{
		box->error = -1;
		box->i -= (box->i - box->intermed_c);
		return (-1);
	}
	else
	{
		box->mbcur = i;
		return (i);
	}
}

void	ptr_cmaj_case(char **str, t_p *box)
{
	if (box->c < 0x80)
		subfunct(str, box, 0, 0);
	else if (box->c < 0x800)
		subfunct(str, box, 11, 0xc0);
	else if (box->c < 0x10000)
		subfunct(str, box, 16, 0xe0);
	else if (box->c < 0x200000)
		subfunct(str, box, 21, 0xf0);
}

int		ptr_cmaj(char **str, va_list ap, t_p *box)
{
	int i;

	box->c = va_arg(ap, int);
	if ((i = error_case(box)) == -1)
		return (1);
	box->delta = box->width - i;
	if (!(box->flags & (1 << minus)))
		ft_insert_spaces(str, box);
	ptr_cmaj_case(str, box);
	if (box->width)
		ft_insert_spaces(str, box);
	ft_buffalloc(str, box, 1);
	return (1);
}
