/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:05:16 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/07 23:05:18 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_modifiers(char **format, t_p *box)
{
	int i;

	i = 0;
	if ((*format)[i] == 'h' && (*format)[i + 1] == 'h' && (i = i + 2))
		box->modifier |= (1 << hashash);
	else if ((*format)[i] == 'h' && (i = i + 1))
		box->modifier |= (1 << hash);
	else if ((*format)[i] == 'l' && (*format)[i + 1] == 'l' && (i = 2))
		box->modifier |= (1 << ellell);
	else if ((*format)[i] == 'l' && (i = i + 1))
		box->modifier |= (1 << ell);
	else if ((*format)[i] == 'j' && (i = i + 1))
		box->modifier |= (1 << jay);
	else if ((*format)[i] == 'z' && (i = i + 1))
		box->modifier |= (1 << zed);
	*format += i;
	return (i);
}
