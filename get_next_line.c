/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:11:44 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/09 23:11:05 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	static char	*copy;
	ssize_t		read_file;
	char		*return_word;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_file = 0;
	copy = get_file_and_copy(fd, buf, copy, read_file);
	if (!copy || copy[0] == '\0')
	{
		free(copy);
		copy = NULL;
		return (free_null(buf));
	}
	return_word = NULL;
	copy = n_copy(copy, ft_strlen(copy), &return_word);
	free(buf);
	return (return_word);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		line = get_next_line(0);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
