/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:06:24 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/07 23:06:26 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	box_initializer(t_p *box)
{
	box->flags = 0;
	box->width = 0;
	box->precision = -1;
	box->modifier = 0;
	box->delta = 0;
	box->toskip = 0;
	box->err = 1;
	box->error = 0;
	box->tmp = 0;
}
