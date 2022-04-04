/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_cmd_endline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:24:40 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/04/04 18:35:35 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int verify_cmd_endline(char *str)
{
    int endline;
    int i;

    endline = 0;
    i = 0;
    if (!str)
        return (-1);
    while (str[i] != '\0')
    {
        if (str[i] == ';')
        {
            if (str[i + 1] == ';')
                return (-1);
            else
                endline++;
        }
        i++;
    }
    return (endline);
}