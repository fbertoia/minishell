/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:27:00 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/07 19:27:02 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_s_null_case(char **str, t_p *box)
{
	char *null;

	null = "(null)";
	while (*null && box->precision)
	{
		(*str)[box->i] = *null;
		null++;
		box->i += 1;
		box->ret += 1;
		box->precision -= 1;
		ft_buffalloc(str, box, 1);
	}
}

void	ptr_s_regular_case(char **str, char *s, t_p *box)
{
	while (*s && box->precision)
	{
		(*str)[box->i] = *s;
		box->i += 1;
		s++;
		box->precision -= 1;
		box->ret += 1;
		ft_buffalloc(str, box, 1);
	}
}

int		ptr_s(char **str, va_list ap, t_p *box)
{
	char	*s;
	int		tmp;

	if (((box->modifier & (1 << ell))))
		return (ptr_smaj(str, ap, box));
	s = va_arg(ap, char *);
	box->precision = (box->precision == -1 ? INT_MAX : box->precision);
	if (!s)
		box->width -= (6 > box->precision ? box->precision : 6);
	tmp = (!s ? 0 : ft_strlen(s));
	tmp = (tmp > box->precision ? box->precision : tmp);
	box->delta = box->width - tmp;
	if (!(box->flags & (1 << minus)))
		ft_insert_spaces(str, box);
	if (!s)
		ptr_s_null_case(str, box);
	else
		ptr_s_regular_case(str, s, box);
	if (box->width)
		ft_insert_spaces(str, box);
	return (1);
}
