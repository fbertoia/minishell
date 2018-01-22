/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:53:33 by fbertoia          #+#    #+#             */
/*   Updated: 2017/12/15 03:12:30 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"

# define MODIFIER "hljz"
# define FLAGS "#0- +.*"
# define FLAGSNUM "#0- +.*123456789"
# define NUM "0123456789"

/*
** Colors to use for printf
*/

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define UNDERLIGN "\x1b[4m"
# define BOLD "\x1b[1m"
# define HIDDEN "\x1b[8m"
# define NOCOLOR "\033[0m"

/*
** Management of the buffer
*/

# ifndef BUFF_SIZE_VS
#  define BUFF_SIZE_VS 20000
# endif
# ifndef BUFF_SIZE_ERROR_VS
#  define BUFF_SIZE_ERROR_VS 500
# endif
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

enum	e_flags
{
	hashtag,
	zero,
	minus,
	space,
	plus,
	dot,
	star,
	modulo
};

enum	e_modifiers
{
	hash,
	hashash,
	ell,
	ellell,
	jay,
	zed
};

typedef struct		s_vs
{
	int				flags;
	int				width;
	int				precision;
	int				modifier;
	char			converter;
	int				delta;
	int				err;
	int				error;
	int				mbcur;
	int				ret;
	int				toskip;
	int				i;
	wint_t			c;
	int				intermed_c;
	int				tmp;
	int				phold;
	int				third;
	int				fd;
}					t_vs;

int					vs_ft_printf(const char *format, ...);
int					vs_ft_dprintf(int fd, const char *format, ...);
void				vs_var_reader(char *format, char **str, va_list ap, t_vs *box);
int					vs_reader(char *format, char **str, va_list ap, t_vs *box);
int					vs_ptr_color(char *format, char **str, t_vs *box, va_list ap);
void				vs_ft_copy_colors(char **str, char *color_type, t_vs *box);
void				vs_box_initializer(t_vs *box);
int					vs_ft_flags(char **format, t_vs *box, va_list ap, int stri);
int					vs_ft_modifiers(char **format, t_vs *box);
void				vs_ft_buffalloc(char **ptr, t_vs *box, int type);
int					vs_ptr_s(char **str, va_list ap, t_vs *box);
int					vs_ptr_smaj(char **str, va_list ap, t_vs *box);
int					vs_ptr_c(char **str, va_list ap, t_vs *box);
int					vs_ptr_cmaj(char **str, va_list ap, t_vs *box);
int					vs_ptr_p(char **str, va_list ap, t_vs *box);
int					vs_ptr_pct(char **str, va_list ap, t_vs *box);
int					vs_ptr_d(char **str, va_list ap, t_vs *box);
int					vs_ptr_u(char **str, va_list ap, t_vs *box);
int					vs_ptr_o(char **str, va_list ap, t_vs *box);
int					vs_ptr_x(char **str, va_list ap, t_vs *box);
int					vs_ptr_lambda(char *format, char **str, t_vs *box);
int					vs_ptr_b(char **str, va_list ap, t_vs *box);
void				vs_ptr_c_case(char **str, char c, t_vs *box);
void				vs_ft_insert_spaces(char **str, t_vs *box);
void				vs_ptr_cmaj_case(char **str, t_vs *box);
void				vs_ptr_copy(char **str, char *tab, t_vs *box);
int					vs_error_case(t_vs *box);
void				vs_ptr_s_null_case(char **str, t_vs *box);

char				*vs_ft_lltoa(long long n, t_vs *box);
void				vs_ft_sub_lltoa(long long n, int *i, char **ret);
long long			vs_ft_get_number(va_list ap, t_vs *box);

void				vs_ft_xtoa_insert_spaces(char **str, t_vs *box);
unsigned long long	vs_ft_boux_get_number(va_list ap, t_vs *box);
char				*vs_ft_bouxtoa_base(unsigned long long value, t_vs *box);
void				vs_ft_sub_bouxtoa_base(unsigned long long value,
					t_vs *box, int *i, char **ret);
void				vs_ft_hashtag_box(char **str, t_vs *box, unsigned long long x);
void				vs_ft_bxtoa_insert_flags(char **str,
					t_vs *box, int len, unsigned long long x);
void				vs_ft_flag_reorganize(t_vs *box);
void				vs_ft_unsigned_insert_spaces(char **str, t_vs *box);

#endif
