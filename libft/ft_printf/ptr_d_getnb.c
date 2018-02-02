/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_dmaj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:10:22 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/13 18:10:25 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_get_number(va_list ap, t_p *box)
{
	long long nb;

	nb = 0;
	if (box->modifier & (1 << ellell))
		nb = (long long)va_arg(ap, long long);
	else if (box->modifier & (1 << jay))
		nb = (long long)va_arg(ap, intmax_t);
	else if (box->modifier & (1 << zed))
		nb = (long long)va_arg(ap, long);
	else if (box->modifier & (1 << ell))
		nb = (long long)va_arg(ap, long);
	else if (box->modifier & (1 << hash))
		nb = (long long)(short)va_arg(ap, int);
	else if (box->modifier & (1 << hashash))
		nb = (long long)(char)va_arg(ap, int);
	else
		nb = (long long)va_arg(ap, int);
	return (nb);
}

void		ft_sub_lltoa(long long n, int *i, char **ret)
{
	int				flag;
	long long		nb;

	flag = 0;
	nb = 1000000000000000000;
	while (nb)
	{
		if (n / nb || flag)
		{
			(*ret)[(*i)++] = '0' + (n > 0 ? n / nb : n / -nb);
			flag = 1;
		}
		n %= nb;
		nb /= 10;
	}
}

char		*ft_lltoa(long long n, t_p *box)
{
	char	*ret;
	int		i;

	(void)box;
	if ((ret = (char *)malloc(sizeof(char) * 21)) == NULL)
		return (NULL);
	if (!(i = 0) && n == 0)
		ret[i++] = '0';
	ft_sub_lltoa(n, &i, &ret);
	ret[i] = 0;
	return (ret);
}
