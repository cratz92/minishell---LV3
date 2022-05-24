/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:38:40 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/04/26 14:38:40 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool is_redirection_parse(int type)
{
	return (type == REDIRECTION_IN || type == REDIRECTION_OUT || type == APPEND || type == HEREDOC);
}

bool check_errors(t_token *tok)
{
	if (tok && tok->type == PIPE)
		return (printf("%s `|'\n", SYNTAX_ERR), true);
	while (tok)
	{
		if ((is_redirection_parse(tok->type)) && (!tok->next || tok->next->type != WORD))
		{
			if (tok->next)
				return (printf("%s `%s'\n",
							   SYNTAX_ERR, tok->next->content),
						true);
			return (printf("%s `newline'\n", SYNTAX_ERR), true);
		}
		if (tok->type == PIPE && (!tok->next || (tok->next->type != WORD && !is_redirection_parse(tok->next->type))))
		{
			if (tok->next)
				return (printf("%s `%s'\n",
							   SYNTAX_ERR, tok->next->content),
						true);
			return (printf("%s `newline'\n", SYNTAX_ERR), true);
		}
		tok = tok->next;
	}
	return (false);
}

static t_cmd *new_cmd(t_gc **garbage)
{
	t_cmd *cmd;

	cmd = gc_malloc(sizeof(t_cmd), garbage);
	cmd->cmd_list = NULL;
	cmd->red = NULL;
	cmd->next = NULL;
	return (cmd);
}

static void append_cmd(t_cmd **cmds, t_cmd *cmd)
{
	t_cmd *last;

	if (!cmds)
		return;
	if (!*cmds)
	{
		*cmds = cmd;
		return;
	}
	last = *cmds;
	while (last->next)
		last = last->next;
	last->next = cmd;
}

static char **get_cmd_list(t_token *tok, t_gc **garbage)
{
	char **cmd_list;
	t_token *tmp;
	int i;

	i = 1;
	tmp = tok;
	while (tok && tok->type != PIPE)
	{
		if (tok->type != WORD)
			tok = tok->next;
		else
			i++;
		tok = tok->next;
	}
	cmd_list = gc_malloc(sizeof(char *) * (i + 1), garbage);
	i = 0;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type != WORD)
			tmp = tmp->next;
		else
			cmd_list[i++] = tmp->content;
		tmp = tmp->next;
	}
	cmd_list[i] = NULL;
	return (cmd_list);
}

t_cmd *parse(t_token *tok, t_gc **garbage)
{
	t_cmd *cmds;
	t_cmd *cmd;

	if (!tok)
		return (NULL);
	cmds = NULL;
	while (tok)
	{
		if (!cmds || tok->type == PIPE)
		{
			if (tok->type == PIPE)
				tok = tok->next;
			cmd = new_cmd(garbage);
			append_cmd(&cmds, cmd);
			cmd->cmd_list = get_cmd_list(tok, garbage);
		}
		tok = tok->next;
	}
	return (cmds);
}
