/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_lambda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:55:10 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/13 21:55:12 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_the_length(char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	return (i);
}

static void		ft_insert_spaces_lambda(char **str, t_p *box)
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

static void		ptr_subinsert_char(char *format, char **str, t_p *box, int len)
{
	int i;

	i = 0;
	if (i < len)
	{
		(*str)[box->i] = format[i++];
		box->ret += 1;
		box->i += 1;
		box->toskip += 1;
	}
	ft_insert_spaces_lambda(str, box);
	while (i < len)
	{
		(*str)[box->i] = format[i++];
		box->ret += 1;
		box->i += 1;
		box->toskip += 1;
		ft_buffalloc(str, box, 1);
	}
}

static void		ptr_insert_char(char *format, char **str, t_p *box, int len)
{
	int i;

	i = 0;
	if (box->flags & (1 << minus))
		ptr_subinsert_char(format, str, box, len);
	else
	{
		while (i < len)
		{
			(*str)[box->i] = format[i++];
			box->ret += 1;
			box->i += 1;
			box->toskip += 1;
			ft_buffalloc(str, box, 1);
		}
		if (box->width)
			ft_insert_spaces_lambda(str, box);
	}
}

int				ptr_lambda(char *format, char **str, t_p *box)
{
	int		len;
	int		i;

	i = 0;
	len = get_the_length(format);
	box->delta = box->width - (len ? 1 : 0);
	if (!(box->flags & (1 << minus)))
		ft_insert_spaces_lambda(str, box);
	ptr_insert_char(format, str, box, len);
	return (1);
}
