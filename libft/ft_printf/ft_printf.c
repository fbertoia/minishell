/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:26:48 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 03:32:30 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 									FT_PRINTF
** This function aims at copying the real printf function. It includes the
** management of flags, modifiers, and converters.
** Among additional features, there is the fd descriptor to come.
** Colors can be added, GRN, BLU, RED, YEL, NC (for No Color), UL
** (for UnderLign) and BD (for Bold).
** You can also print binaries with the option %b or %B.
*/

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*tmp;
	char		*buf;
	t_p			box;

	box.fd = 1;
	box.ret = 0;
	box.i = 0;
	box.error = 0;
	buf = NULL;
	ft_buffalloc(&buf, &box, 0);
	tmp = (char *)format;
	va_start(ap, format);
	reader(tmp, &buf, ap, &box);
	va_end(ap);
	ft_buffalloc(&buf, &box, 2);
	return (box.error == -1 ? box.error : box.ret);
}
