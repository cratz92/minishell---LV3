/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:34:27 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/03/21 03:34:27 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void parse_args(char *str)
{
	verify pipes '|'
	/* cmd1 | cmd2 | ... 
		if they exists and if so, how many
	*/

	verify end cmd ';'
	/* cmd1; cmd2; ... 
		if they exists and if so, how many
	*/
	
	verify redirections '<'/'>'/">>"
	/* program < file 
	   cmd1 > file
	   cmd1 >> file
	*/

	split input
	/* split the initial str into small tokens */

	verify cmd (echo, pwd, cd, ...)
	/* search for the command */
	
	verify ''/""
	/* verify is '' or "" exists and if its close */
	
	verify input according to each cmd
	/*      echo str/"str"/-n str/-n "str" 
		cd str/./../~    str=(path)
		pwd (no args)
		export no args/str   str=(name=value)
		unset str      str=(name)
		env (no args)
		exit (no args)
	*/

}


