/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_smaj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:13:47 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/11 14:13:49 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_smaj_checker(t_p *box, wchar_t *s)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = box->precision;
	while (s && *s && k)
	{
		box->c = *s;
		if ((j = error_case(box)) == -1)
			return (-1);
		if (k - j >= 0)
			i += j;
		k -= j;
		s++;
	}
	return (i);
}

int			ptr_smaj(char **str, va_list ap, t_p *box)
{
	int		i;
	wchar_t	*s;

	s = va_arg(ap, wchar_t *);
	if (box->precision == -1)
		box->precision = INT_MAX;
	if ((i = ptr_smaj_checker(box, s)) == -1)
		return (1);
	box->delta = box->width - i;
	if (!(box->flags & (1 << minus)))
		ft_insert_spaces(str, box);
	if (!s)
		ptr_s_null_case(str, box);
	while (s && *s && box->precision)
	{
		box->c = (wint_t)(*(s++));
		if ((box->precision -= error_case(box)) >= 0)
			ptr_cmaj_case(str, box);
	}
	if (box->width)
		ft_insert_spaces(str, box);
	ft_buffalloc(str, box, 1);
	return (1);
}
