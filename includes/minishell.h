/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <fbertoia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:36:55 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/22 02:11:35 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"
# include <ft_printf.h>
# include <errno.h>
# include <signal.h>
# include <limits.h>

# define NUMBER_BUILTIN 6
# define BUFF_SIZE_GNM 4096

extern int			g_sig;
extern int			g_prompt;

typedef struct		s_env
{
	struct s_env	*next;
	char			*name;
	char			*value;
}					t_env;

typedef struct		s_parser
{
	struct s_parser *next;
	char			*arg;
}					t_parser;

typedef struct		s_data
{
	int				i;
	pid_t			parent;
	int				status;
	char			*s;
	char			**split_args;
	char			**sub_env;
	char			*path;
	int				*wait;
	t_env			*env;
	t_env			*copy_env;
	char			**arr_env;
	char			old_dir[PATH_MAX + 1];
	t_parser		*parser;
	int				quotes;
	int				error;
}					t_data;

void				prompt(void *data);

int					parser(t_data *data);

int					copyenv(t_data *data, char **environ);
void				increase_shlvl(t_env *env);
char				**copy_arr_env(t_data *data, t_env *env);
int					ft_copyenvlist(t_env *src, t_env **copy_env);
int					change_var(t_env **env, char *name, char *value);
t_env				*new_env_var(char *name, char *value);
void				add_new_var(char *environ, t_data *data);
int					print_env(t_env *env);
void				print_arr_env(char **env);
void				setpath(char **env, char ***paths);
int					callsystem(char *argv[], t_env **envp,
					t_data *data);
int					callfunction(char **args, t_data *data,
					t_env **env);
void				handlesig(int num);

int					cd(char *argv[], t_env **env, t_data *data);
int					echo(char *argv[], t_env **env, t_data *data);
int					ft_exit(char *argv[], t_env **env, t_data *data);
int					ft_setenv(char *argv[], t_env **env, t_data *data);
int					ft_setenv2(char *name, char *value, t_env **env);
int					ft_unsetenv(char *argv[], t_env **env,
					t_data *data);
int					ft_unsetenv2(char *av, t_env **env);
int					ft_env(char *argv[], t_env **env, t_data *data);

void				del_args(char ***arr);
void				delstr(int nb_args, ...);
void				delete_env(t_env **env);
void				delete_parser(t_parser **parser);
void				free_all(t_data *data);

int					print_message(char *message,
char *function_name);
int					print_usage_env(char c, int option);

t_env				*elem_name(t_env *env, char *str);

#endif
