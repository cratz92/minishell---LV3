/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:38:37 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/04/26 14:38:37 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

static bool is_redirection(char *s)
{
	return ((*s == '<' && *(s + 1) == '<') || (*s == '>' && *(s + 1) == '>') || (*s == '<') || (*s == '>'));
}

static t_list *quote_error(void)
{
	printf("syntax error: missing to close quotes\n");
	return (NULL);
}

char *append_char(char *str, char c)
{
	char *tmp;
	int len;

	if (!str)
	{
		tmp = malloc(2);
		tmp[0] = c;
		tmp[1] = 0;
		return (tmp);
	}
	len = ft_strlen(str);
	tmp = malloc(len + 2);
	ft_strlcpy(tmp, str, len + 1);
	tmp[len] = c;
	tmp[len + 1] = 0;
	return (tmp);
}

static char *special(char *s, t_list **tokens, t_gc **garbage)
{
	t_list *last_token;
	int n;
	int i;

	last_token = ft_lstlast(*tokens);
	n = 1;
	if ((*s == '>' && *(s + 1) == '>') || (*s == '<' && *(s + 1) == '<'))
		n = 2;
	if (last_token->content)
		ft_lstadd_back(tokens,
					   collect(ft_lstnew(collect(ft_substr(s, 0, n), garbage)), garbage));
	else
	{
		i = -1;
		while (++i < n)
			last_token->content =
				collect(append_char(last_token->content, *(s + i)), garbage);
	}
	if (*(s + n) && !is_space(*(s + n + 1)) && *(s + n + 1))
		ft_lstadd_back(tokens, collect(ft_lstnew(NULL), garbage));
	s += n;
	return (s);
}

static void sub_handle_quotes(t_list *token, char *s, char c)
{
	if (*(s + 1) == '\\')
		token->content = append_char(token->content, '\\');
	else if (*(s + 1) == c)
		token->content = append_char(token->content, c);
	else
	{
		token->content = append_char(token->content, *s);
		token->content = append_char(token->content, *(s + 1));
	}
}

char *handle_quotes(char *s, t_list **tokens, t_gc **garbage)
{
	t_list *token;
	char c;

	c = *(s++);
	token = ft_lstlast(*tokens);
	if (*s == c && !token->content)
		token->content = "";
	while (*s && *s != c)
	{
		if (*s == '\\' && c == '"' && *(s + 1))
		{
			sub_handle_quotes(token, s, c);
			s += 2;
		}
		else if (*s != c)
		{
			token->content = append_char(token->content, *(s++));
			if ((c == '\'' && *(s - 1) == '$') || *(s - 1) == '*')
				token->content = append_char(token->content, -1);
		}
		collect(token->content, garbage);
	}
	return (s);
}

t_list *tokenize(char *s, t_gc **garbage)
{
	t_list *tokens;
	t_list *token;

	tokens = NULL;
	if (!is_space(*s))
		ft_lstadd_back(&tokens, collect(ft_lstnew(NULL), garbage));
	while (*s)
	{
		if ((!tokens || is_space(*s)) && (*(s + 1) && !is_space(*(s + 1))))
			ft_lstadd_back(&tokens, collect(ft_lstnew(NULL), garbage));
		while (*s == '|' || is_redirection(s))
			s = special(s, &tokens, garbage);
		token = ft_lstlast(tokens);
		if (*s == '\'' || *s == '"')
		{
			s = handle_quotes(s, &tokens, garbage);
			if (*s != '\'' && *s != '"')
				return (quote_error());
		}
		else if (tokens && !is_space(*s))
			token->content = collect(append_char(token->content, *s), garbage);
		if (*s)
			s++;
	}
	return (tokens);
}
