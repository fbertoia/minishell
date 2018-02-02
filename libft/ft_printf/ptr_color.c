/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:46:36 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 03:11:53 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_copy_colors(char **str, char *color_type, t_p *box)
{
	int i;

	i = 0;
	while (color_type[i])
	{
		(*str)[box->i] = color_type[i];
		box->i += 1;
		i++;
	}
}

static int		ft_strrgb_sec(char *format, char *colorrgb, va_list ap,
				char *tmp)
{
	while (*format && *format != ']')
	{
		ft_strcat(colorrgb, ";");
		if (*format == '*')
		{
			ft_strcat(colorrgb,
			(tmp = ft_itoa((int)(unsigned char)va_arg(ap, int))));
			free(tmp);
			format++;
		}
		else if (ft_isdigit(*format))
		{
			ft_strcat(colorrgb, (tmp = ft_itoa(ft_atoi(format))));
			free(tmp);
			while (*format && ft_isdigit(*format))
				format++;
		}
		if (*format && *format != ',' && *format != ']')
			return (0);
		if (*format && *format != ']')
			format++;
	}
	ft_strcat(colorrgb, "m");
	return (1);
}

static void		ft_strrgb(char *format, char **str, t_p *box, va_list ap)
{
	char *colorrgb;
	char *tmp;

	tmp = NULL;
	if ((colorrgb = (char *)malloc(sizeof(char) * 25)) == NULL)
		exit(EXIT_FAILURE);
	ft_bzero(colorrgb, 25);
	ft_strcpy(colorrgb, "\x1b[38;2");
	if (ft_strrgb_sec(format, colorrgb, ap, tmp))
		ft_copy_colors(str, colorrgb, box);
	free(colorrgb);
}

static int		ft_insert_colors(char *format, char **str, t_p *box, va_list ap)
{
	char	*colorrgb;

	colorrgb = NULL;
	if (ft_strnequ(format, "[BLU]", 4))
		colorrgb = BLUE;
	else if (ft_strnequ(format, "[RED]", 5))
		colorrgb = RED;
	else if (ft_strnequ(format, "[GRN]", 4))
		colorrgb = GREEN;
	else if (ft_strnequ(format, "[YEL]", 5))
		colorrgb = YELLOW;
	else if (ft_strnequ(format, "[BD]", 4))
		colorrgb = BOLD;
	else if (ft_strnequ(format, "[UL]", 4))
		colorrgb = UNDERLIGN;
	else if (ft_strnequ(format, "[HD]", 4))
		colorrgb = HIDDEN;
	else if (ft_strnequ(format, "[NC]", 2))
		colorrgb = NOCOLOR;
	if (colorrgb)
		ft_copy_colors(str, colorrgb, box);
	else
		ft_strrgb(format + 1, str, box, ap);
	return (1);
}

int				ptr_color(char *format, char **str, t_p *box, va_list ap)
{
	int i;
	int j;

	i = 0;
	if ((j = ft_strnindex(format, ']', 25)) != -1)
	{
		i = ft_insert_colors(format, str, box, ap);
		box->toskip += j;
	}
	ft_buffalloc(str, box, 1);
	return (1);
}
