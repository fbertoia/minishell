/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:59:19 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 19:59:22 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	char		*tmp;
	char		*buf;
	t_p			box;

	box.ret = 0;
	box.i = 0;
	box.error = 0;
	box.fd = fd;
	buf = NULL;
	ft_buffalloc(&buf, &box, 0);
	tmp = (char *)format;
	va_start(ap, format);
	reader(tmp, &buf, ap, &box);
	va_end(ap);
	ft_buffalloc(&buf, &box, 2);
	return (box.error == -1 ? box.error : box.ret);
}
