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
#include <errno.h>

#define SUCESS 0

// error codes

#define ERROR_127 127

// structs

typedef struct s_args
{
	int haspipes;
	int nbr_pipes;
	int hasquotes;
} t_args;

typedef struct s_pipe
{
	int id;
	char *cmd;
	t_pipe *previous_pipe;
	t_pipe *next_pipe;
} t_pipe;

typedef struct s_main
{
	t_args args;
	t_pipe *pipes;
} t_main;

// ********** PROTOTYPES  ***********
// minishell.c

void init(void);

// parse.c

void parse_args(char *str);

#endif
