/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:23:22 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/04/04 20:52:12 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int number_of_splits(char *str)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '|' || str[i] == ';')
            count++;
        i++;
    }
    return (count);
}

static char **ft_malloc(char *str)
{
    int nbr_tokens;
    char **tmp_str;

    nbr_tokens = number_of_cuts(str);
    tmp_str = malloc(sizeof(*tmp_str) * (nbr_tokens + 2));
    if (!tmp_str)
        return (NULL);
    return (tmp_str);
}

char    **ft_split_pipes_endlines(char const *str)
{
    char **tmp_tokens;
    t_index i;

    if (str == NULL || str[0] == NULL)
        return (NULL);
    tmp_tokens = ft_malloc(str);
    if (!tmp_tokens)
        return (NULL);
    i.str_i = -1;
    i.index = 0;
    while (str[++i.str_i] != '\0')
    {
        if (str[i.str_i] == '|' || str[i.str_i] == ';')
        {
            i.finish = i.str_i;
            tmp_tokens[i.index] = ft_substr(str, i.start, (i.finish - i.start));
            if (!tmp_tokens[i.index++])
                return (NULL);
            i.start = i.str_i;
        }
    }
    tmp_tokens[i.index] = '\0';
    return (tmp_tokens);
}
