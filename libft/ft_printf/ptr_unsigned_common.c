/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_unsigned_common.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:56:46 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 17:58:52 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_sub_bouxtoa_base(unsigned long long value, t_p *box,
					int *i, char **ret)
{
	char	*base_val;
	int		base;

	if (box->converter == 'x' || box->converter == 'X' ||
	box->converter == 'p')
		base = 16;
	else if (box->converter == 'o' || box->converter == 'O')
		base = 8;
	else if (box->converter == 'u' || box->converter == 'U')
		base = 10;
	else
		base = 2;
	if (box->converter == 'X')
		base_val = "0123456789ABCDEF";
	else
		base_val = "0123456789abcdef";
	while (value > 0)
	{
		(*ret)[*i] = base_val[value % base];
		value /= base;
		(*i)++;
	}
}

char				*ft_bouxtoa_base(unsigned long long value, t_p *box)
{
	char	*ret;
	int		i;

	i = 0;
	if ((ret = (char*)malloc(sizeof(char) * 18)) == NULL)
		return (NULL);
	if (!value)
		ret[i++] = '0';
	ft_sub_bouxtoa_base(value, box, &i, &ret);
	ret[i] = 0;
	return (ft_strrev(ret));
}

void				ft_hashtag_box(char **str, t_p *box, unsigned long long x)
{
	if (box->flags & (1 << hashtag) && (x ||
	(box->converter == 'o' || box->converter == 'O' ? box->tmp : 0)))
	{
		(*str)[box->i] = '0';
		box->i += 1;
		box->ret += 1;
		if (box->converter == 'X' || box->converter == 'x' ||
		box->converter == 'b' || box->converter == 'B')
		{
			if (box->converter == 'x')
				(*str)[box->i] = 'x';
			else if (box->converter == 'X')
				(*str)[box->i] = 'X';
			else if (box->converter == 'b')
				(*str)[box->i] = 'b';
			else
				(*str)[box->i] = 'B';
			box->i += 1;
			box->ret += 1;
		}
	}
}

unsigned long long	ft_boux_get_number(va_list ap, t_p *box)
{
	unsigned long long nb;

	nb = 0;
	if (box->modifier & (1 << ellell))
		nb = (unsigned long long)va_arg(ap, unsigned long long);
	else if (box->modifier & (1 << jay))
		nb = (unsigned long long)va_arg(ap, uintmax_t);
	else if (box->modifier & (1 << zed))
		nb = (unsigned long long)va_arg(ap, size_t);
	else if (box->modifier & (1 << ell))
		nb = (unsigned long long)va_arg(ap, unsigned long);
	else if (box->modifier & (1 << hash))
		nb = (unsigned long long)(unsigned short)va_arg(ap, unsigned int);
	else if (box->modifier & (1 << hashash))
		nb = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	else
		nb = (unsigned long long)va_arg(ap, unsigned int);
	return (nb);
}

void				ft_flag_reorganize(t_p *box)
{
	if (box->flags & (1 << minus) || box->precision != -1)
		box->flags &= ~(1 << zero);
	if (box->flags & (1 << plus))
		box->flags &= ~(1 << space);
}
