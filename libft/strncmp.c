/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 01:25:16 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/03/21 01:25:16 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str;
	unsigned char *str2;
	size_t i;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*(str + i) == *(str2 + i) && (i < n - 1) && *(str + i))
		i++;
	return (*(str + i) - *(str2 + i));
}
