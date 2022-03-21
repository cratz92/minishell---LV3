# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 18:00:11 by cbrito-l          #+#    #+#              #
#    Updated: 2022/03/20 18:00:11 by cbrito-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS_DIR	= src/
LIBFT_SRCS_DIR	= libft/
INC_DIR		= include/

SRCS		= $(addprefix $(SRCS_DIR), \
				minishell.c \
				parse.c)

LIBFT_SRCS	= $(addprefix $(LIBFT_SRCS_DIR), \
				strncmp.c)

OBJS		= $(SRCS:.c=.o)
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)
INC			= $(INC_DIR)

INC_PARAMS	= $(INC:%=-I%)
CC			= gcc
#CFLAGS		= -Werror -Wall -Wextra $(INC_PARAMS)
CFLAGS		= -Wall -Wextra $(INC_PARAMS)

all			: $(NAME)

$(NAME)		: $(OBJS) $(LIBFT_OBJS)
			  $(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) -lreadline -o $(NAME)

clean		:
			 rm -rf $(OBJS) $(LIBFT_OBJS)

fclean		: clean
			  rm -rf $(NAME)

re			: fclean all
