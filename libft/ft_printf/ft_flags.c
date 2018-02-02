/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:42:02 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/07 17:42:04 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flagnum(char *format, t_p *box)
{
	int i;

	i = 0;
	box->width = (unsigned int)ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return (i);
}

static int		ft_flagcomma(char *format, t_p *box, va_list ap)
{
	int i;

	i = 1;
	if (format[i] == '*')
	{
		box->precision = va_arg(ap, unsigned int);
		if (box->precision < 0)
		{
			box->precision = -1;
			box->flags |= (1 << zero);
		}
		i++;
	}
	else if (format[i] >= '0' && format[i] <= '9')
	{
		box->precision = (unsigned int)ft_atoi(format + 1);
		while (format[i] && format[i] >= '0' && format[i] <= '9')
			i++;
	}
	else
		box->precision = 0;
	return (i);
}

static int		ft_flagstar(t_p *box, va_list ap)
{
	box->width = va_arg(ap, unsigned int);
	if (box->width < 0)
	{
		box->flags |= (1 << minus);
		box->width *= -1;
	}
	return (1);
}

int				ft_flags(char **format, t_p *box, va_list ap, int stri)
{
	int		i;

	i = 0;
	if (**format == '*')
		i += ft_flagstar(box, ap);
	else if (**format >= '1' && **format <= '9')
		i += ft_flagnum(*format, box);
	else if (**format == '.')
		i += ft_flagcomma(*format, box, ap);
	else
	{
		box->flags |= (1 << stri);
		i++;
	}
	*format += i;
	return (i);
}
