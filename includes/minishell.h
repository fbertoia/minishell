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

# include "minishell.h"
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

extern int g_sig;

typedef struct    s_data
{
	int		i;
	pid_t	parent;
	struct stat *buf;
	int		status;
	char	*s;
	char	**split_args;
	char	**env;
	char	**sub_env;
	char	*path;
	int		*wait;
	char	old_dir[PATH_MAX + 1];
}                 t_data;

int prompt(void);

int copyenv(t_data *data, char **environ);
void setpath(char **env, char ***paths);
int callsystem(char *argv[], char *envp[], t_data *data);
int callfunction(t_data *data);
void handlesig(int num);


int cd(char *argv[], char *envp[], t_data *data);
int echo(char *argv[], char *envp[], t_data *data);
int ft_exit(char *argv[], char *envp[], t_data *data);
int ft_setenv(char *argv[], char *envp[], t_data *data);
int ft_unsetenv(char *argv[], char *envp[], t_data *data);

int env(char *argv[], char *envp[], t_data *data);
char *get_envvar(char **env, char *str);

void del_args(char ***arr);
void delstr(int nb_args, ...);
char *ft_strjoin_multiple(int nb_args, ...);

#endif
