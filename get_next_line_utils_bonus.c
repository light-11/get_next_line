/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:48:57 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/04 08:08:10 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*n_copy(char *copy, ssize_t count, char **return_word)
{
	int		i;
	int		j;
	char	*copy_new;

	i = 0;
	j = 0;
	i = cut_word(copy, return_word);
	if (i == -1)
		return (free_null(copy));
	if (copy[i] == '\0')
		return (free_null(copy));
	copy_new = malloc(sizeof(char) * (count - i) + 1);
	if (!copy_new)
		return (free_null(copy));
	while (copy[i])
	{
		copy_new[j] = copy[i];
		i++;
		j++;
	}
	copy_new[j] = '\0';
	free(copy);
	return (copy_new);
}
