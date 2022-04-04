/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:33:26 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/04/04 18:10:40 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int verify_pipes(char *str)
{
    int pipes;
    int i;

    pipes = 0;
    i = 0;
    if (!str)
        return (-1);
    while (str[i] != '\0')
    {
        if (str[i] == '|')
        {
            if (str[i + 1] == '|')
                i++;
            else
                pipes++;
        }
        i++;
    }
    return (pipes);
}