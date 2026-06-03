/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:48:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/04 07:54:56 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

char	*free_null(char *s)
{
	free(s);
	return (NULL);
}

char	*buf_insert(char *buf, ssize_t count, char *copy, ssize_t read_file)
{
	int		i;
	int		j;
	char	*copy_all;

	i = 0;
	j = 0;
	copy_all = malloc(sizeof(char) * (count + read_file + 1));
	if (!copy_all)
		return (free_null(copy));
	if (copy)
	{
		while (copy[i])
		{
			copy_all[i] = copy[i];
			i++;
		}
	}
	while (buf[j])
	{
		copy_all[i + j] = buf[j];
		j++;
	}
	copy_all[i + j] = '\0';
	free(copy);
	return (copy_all);
}

int	cut_word(char *copy, char **return_word)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (copy[i] != '\0' && copy[i] != '\n')
		i++;
	if (copy[i] == '\n')
		i++;
	*return_word = malloc(sizeof(char) * i + 1);
	if (!*return_word)
		return (-1);
	while (copy[j] != '\0' && copy[j] != '\n')
	{
		(*return_word)[j] = copy[j];
		j++;
	}
	if (copy[j] == '\n')
	{
		(*return_word)[j] = '\n';
		j++;
	}
	(*return_word)[j] = '\0';
	return (j);
}
char	*get_file_and_copy(int fd, char *buf, char *copy, ssize_t read_file)
{
	while (1)
	{
		if (copy)
		{
			if (ft_strchr(copy, '\n'))
				break ;
		}
		read_file = read(fd, buf, BUFFER_SIZE);
		if (read_file < 0)
		{
			free(copy);
			copy = NULL;
			return (free_null(buf));
		}
		if (read_file == 0)
			break ;
		buf[read_file] = '\0';
		if (copy)
			copy = buf_insert(buf, ft_strlen(copy), copy, read_file);
		else
			copy = buf_insert(buf, 0, copy, read_file);
		if (!copy)
			return (free_null(buf));
	}
	return (copy);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*copy[OPEN_MAX];
	ssize_t		read_file;
	char		*return_word;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_file = 0;
	copy[fd] = get_file_and_copy(fd, buf, copy[fd], read_file);
	if (!copy[fd] || copy[fd][0] == '\0')
	{
		free(copy[fd]);
		copy[fd] = NULL;
		return (free_null(buf));
	}
	return_word = NULL;
	copy[fd] = n_copy(copy[fd], ft_strlen(copy[fd]), &return_word);
	free(buf);
	return (return_word);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int fd1;
// 	int fd2;
// 	char *line;

// 	fd1 = open("a.txt", O_RDONLY);
// 	fd2 = open("b.txt", O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0)
// 		return (1);

// 	line = get_next_line(fd1);
// 	printf("fd1: %s", line);
// 	free(line);

// 	line = get_next_line(fd2);
// 	printf("fd2: %s", line);
// 	free(line);

// 	line = get_next_line(fd1);
// 	printf("fd1: %s", line);
// 	free(line);

// 	line = get_next_line(fd2);
// 	printf("fd2: %s", line);
// 	free(line);

// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }