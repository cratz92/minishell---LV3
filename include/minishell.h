/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:59:01 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/03/20 17:59:01 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include <termios.h>
#include <stdbool.h>

#define SUCESS 0

// error codes

#define ERROR_127 127
#define ERROR_1 1

// structs

typedef struct s_index
{
	int start;
    int finish;
    int index;
    int str_i;
} t_index;

typedef struct s_args
{
	//bool	pipes;
	int nbr_pipes;
	//bool	endline;
	int	nbr_endline;
	char **tokens;
} t_args;

typedef struct s_cmd
{
	int id;
	char *cmd;
	t_cmd *previous_cmd;
	t_cmd *next_cmd;
} t_cmd;

typedef struct s_main
{
	t_args args;
	t_cmd *cmds;
} t_main;


t_main	global = {};

// ********** PROTOTYPES  ***********
// minishell.c

void init(void);

// parse.c

t_args parse_args(char *str);

// verify_pipes.c

int verify_pipes(char *str);

// verify_cmd_endline.c

int verify_cmd_endline(char *str);

// utils.c 

char    **ft_split_pipes_endlines(char const *str);

#endif
