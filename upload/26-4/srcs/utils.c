/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:38:32 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/04/26 14:38:32 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clear(t_gc **garbage)
{
	t_gc *tmp;

	while (*garbage)
	{
		tmp = (*garbage)->next;
		free((*garbage)->rubbish);
		free(*garbage);
		*garbage = tmp;
	}
}

static void allocation_error(t_gc **garbage)
{
	perror("Error");
	clear(garbage);
	exit(0);
}

void *collect(void *rubbish, t_gc **garbage)
{
	t_gc *bin;

	if (!garbage)
		return (NULL);
	if (!rubbish)
		allocation_error(garbage);
	bin = malloc(sizeof(t_gc));
	if (!bin)
		allocation_error(garbage);
	bin->rubbish = rubbish;
	bin->next = (*garbage);
	(*garbage) = bin;
	return (rubbish);
}

void *gc_malloc(size_t size, t_gc **garbage)
{
	return (collect(malloc(size), garbage));
}
