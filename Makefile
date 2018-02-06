# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <fbertoia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 11:38:20 by fbertoia          #+#    #+#              #
#    Updated: 2018/02/04 01:58:03 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = includes
INCLUDES_H = includes/minishell.h
INCLUDES_LIBFT = ./libft/includes
VPATH = ./obj:./srcs:./srcs/main:srcs/builtins:srcs/env:srcs/utilities
SRCS_MINISHELL = minishell.c prompt.c cd.c \
echo.c env.c ft_exit.c ft_setenv.c ft_unsetenv.c callsystem.c copyenv.c \
callfunction.c handlesig.c del.c print.c list.c addenv.c\
change_var.c increase_shlvl.c parser.c
LIB_DIR = ./libft
LIB_PATH = $(LIB_DIR)/libft.a
LIB_NAME = ft
OBJS = $(SRCS_MINISHELL:.c=.o)
OBJS_WITH_PATH = $(OBJS:%.o=obj/%.o)

all: library directory $(NAME)

$(NAME): $(OBJS) $(OBJS_WITH_PATH) $(LIB_PATH) $(INCLUDES_H)
	$(CC) $(CFLAGS) $(OBJS_WITH_PATH)  -L$(LIB_DIR) -l$(LIB_NAME) -o $@

library:
	@make -C $(LIB_DIR)

directory:
	@mkdir -p obj

%.o: %.c $(INCLUDES_H)
	$(CC) -o obj/$@ -c $(CFLAGS) $(CFLAGS_COL) -I$(INCLUDES) -I$(INCLUDES_LIBFT) $<

clean:
	rm -f $(OBJS_WITH_PATH)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all
