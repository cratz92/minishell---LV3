/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:27:43 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/04/26 14:27:43 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

// libraries
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

// lexer
#define WORD 1U
#define PIPE 2U
#define REDIRECTION_IN 4U
#define REDIRECTION_OUT 8U
#define APPEND 16U
#define HEREDOC 32U

// parser:
#define SYNTAX_ERR "syntax error: unexpected token"

// structs
typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

typedef struct s_gc
{
	void *rubbish;
	struct s_gc *next;
} t_gc;

typedef struct s_token
{
	char *content;
	unsigned int type;
	struct s_token *next;
} t_token;

typedef struct s_red
{
	int type;
	char *file;
	int fd;
	struct s_red *next;
} t_red;

typedef struct s_cmd
{
	char **cmd_list;
	t_red *red;
	struct s_cmd *next;
} t_cmd;

// token
t_list *tokenize(char *s, t_gc **garbage);
char *handle_quotes(char *s, t_list **tokens, t_gc **garbage);
char *append_char(char *str, char c);

// lexer
t_token *lexer(t_list *toks, t_gc **garbage);

// parse
bool is_redirection_parse(int type);
bool check_errors(t_token *tok);
t_cmd *parse(t_token *tok, t_gc **garbage);

// utils
void *collect(void *rubbish, t_gc **garbage);
void *gc_malloc(size_t size, t_gc **garbage);
void clear(t_gc **garbage);

#endif
