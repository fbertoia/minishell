/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:57:55 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 19:57:57 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	var_reader(char *format, char **str, va_list ap, t_p *box)
{
	static int	(*ptr_ft[])(char **, va_list, t_p*) = {&ptr_s, &ptr_smaj,
	&ptr_c, &ptr_cmaj, &ptr_p, &ptr_pct, &ptr_d, &ptr_d, &ptr_d, &ptr_u,
	&ptr_u, &ptr_o, &ptr_o, &ptr_x, &ptr_x, &ptr_b, &ptr_b};
	int			stri;
	char		*converter;

	converter = "sScCp%diDuUoOxXbB";
	while (*format && (stri = ft_strindex(FLAGSNUM, *format)) != -1 && box->err)
		box->toskip += ft_flags(&format, box, ap, stri);
	while (*format && ft_strindex(MODIFIER, *format) != -1 && box->err)
		box->toskip += ft_modifiers(&format, box);
	if (*format && (stri = ft_strindex(converter, *format)) != -1 && box->err)
	{
		box->converter = converter[stri];
		box->toskip += ptr_ft[stri](str, ap, box);
		if (box->error != -1)
			box->intermed_c = box->i;
	}
	else if (*format == '[')
		box->toskip += ptr_color(format, str, box, ap);
	else
		ptr_lambda(format, str, box);
}

int		reader(char *format, char **str, va_list ap, t_p *box)
{
	box->intermed_c = 0;
	while (*format && box->error != -1)
	{
		box_initializer(box);
		if (*format == '%')
			var_reader(++format, str, ap, box);
		format += box->toskip;
		while (*format && *format != '%' && box->error != -1)
		{
			(*str)[box->i] = *(format++);
			box->i += 1;
			box->ret += 1;
			ft_buffalloc(str, box, 1);
		}
	}
	return (box->i);
}
