# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <fbertoia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 11:38:20 by fbertoia          #+#    #+#              #
#    Updated: 2018/01/22 02:02:48 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall
INCLUDES = includes
INCLUDES_H = includes/minishell.h
INCLUDES_LIBFT = ./libft/includes
DIR_MINISHELL = srcs
SRCS_MINISHELL = $(addprefix $(DIR_MINISHELL)/, minishell.c prompt.c cd.c \
echo.c env.c ft_exit.c ft_setenv.c ft_unsetenv.c callsystem.c copyenv.c \
callfunction.c setpath.c)

LIB_DIR = ./libft
LIB_PATH = $(LIB_DIR)/libft.a
LIB_NAME = ft
OBJS_MINISHELL = $(SRCS_MINISHELL:$(DIR_MINISHELL)/%.c=$(DIR_MINISHELL)/obj/%.o)

all: library $(NAME)

$(NAME): $(OBJS_MINISHELL) $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS_MINISHELL) -L$(LIB_DIR) -l$(LIB_NAME) -o $@

library:
	make -C $(LIB_DIR)

$(DIR_MINISHELL)/obj/%.o: $(DIR_MINISHELL)/%.c $(INCLUDES_H)
	$(CC) -o $@ -c $(CFLAGS) $(CFLAGS_COL) -I$(INCLUDES) -I$(INCLUDES_LIBFT) $<

clean:
	rm -f $(OBJS_MINISHELL)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all
