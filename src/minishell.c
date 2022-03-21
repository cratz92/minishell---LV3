/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:59:10 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/03/20 17:59:10 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void handle_ctrlc(int sig)
{
	(void)sig;

	write(1, "\n", 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void init()
{
	char *cmd_buff;

	while (1)
	{
		// read stdin
		cmd_buff = readline("minishell$> ");
		// printf("%s \n", cmd_buff);

		if (!cmd_buff)
			break;

		if (!ft_strncmp(cmd_buff, "exit", 5))
			break;

		add_history(cmd_buff);

		// parse args
		parse_args(cmd_buff);

		// execute parsed args

		// stuff to do before exit
		free(cmd_buff);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	struct termios term;

	if (argc != 1)
	{
		write(1, "plz initialize with ./minishell with no args\n", 45);
		return (ERROR_127);
	}

	// init signals to handle ctrl-c/-backstab/-d
	signal(SIGINT, handle_ctrlc);

	if (tcgetattr(STDIN_FILENO, &term) != 0)
	{
		perror("tcgetattr() error");
		exit(errno);
	}
	else
	{
		term.c_lflag &= ~(ECHOCTL);
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}

	// main loop
	init();

	// shutdown / cleanup

	return (SUCESS);
}
