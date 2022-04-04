/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 01:25:53 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/03/21 01:25:53 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// LIBC FUNCTIONS

size_t ft_strlen(const char *s);
size_t ft_strlcat(char *dest, const char *src, size_t destsize);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_atoi(const char *str);
int ft_isalpha(int c);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *str, char charset);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
bool    ft_ternary(int condition);


#endif
