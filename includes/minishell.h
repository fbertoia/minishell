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

#include "minishell.h"
#include<stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include "libft.h"

#define NUMBER_BUILTIN 6

extern int sig;

typedef struct    s_data
{
  int i;
  pid_t parent;
  char *s;
  char **split_args;
  char **env;
  char **sub_env;
  char **path;
  int *wait;
}                 t_data;

int prompt(void);

int ft_strindexstr(char *dest[NUMBER_BUILTIN], char *src);
int copyenv(t_data *data, char **environ);
void setpath(char **env, char ***paths);
int callsystem(char *argv[], char *envp[], t_data *data);
int callfunction(t_data *data);
int ft_strindexstr(char *dest[NUMBER_BUILTIN], char *src);
void handlesig(int num);


int cd(char *argv[], char *envp[], t_data *data);
int echo(char *argv[], char *envp[], t_data *data);
int env(char *argv[], char *envp[], t_data *data);
int ft_exit(char *argv[], char *envp[], t_data *data);
int ft_setenv(char *argv[], char *envp[], t_data *data);
int ft_unsetenv(char *argv[], char *envp[], t_data *data);

void del_arrstr(char ***arr);
void delstr(int nb_args, ...);

#endif
