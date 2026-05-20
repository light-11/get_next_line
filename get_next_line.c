/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:11:44 by ayanaga           #+#    #+#             */
/*   Updated: 2026/05/20 22:57:30 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*buf_insert(char *buf, ssize_t count, char *copy)
{
	int		i;
	int		j;
	char	*copy_all;

	i = 0;
	j = 0;
	copy_all = malloc(sizeof(char) * (count + BUFFER_SIZE + 1));
	if (!copy_all)
		return (NULL);
	while (copy[i])
		copy_all[i] = copy[i];
	while (buf[j])
		copy_all[i + j] = buf[j];
	copy_all[i + j] = '\0';
	free(copy);
	return (copy_all);
}

static int	*cut_word(char *copy, ssize_t count, char *return_word)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (copy[i] != '\0' && copy[i] != '\n')
		i++;
	if (copy[i] == '\n')
		i++;
	return_word = malloc(sizeof(char) * i + 1);
	i = 0;
	while (copy[i] != '\0' && copy[i] != '\n')
	{
		return_word[i] = copy[i];
		i++;
	}
	if (copy[i] == '\n')
	{
		i++;
		return_word[i] = '\n';
	}
	return (i);
}

static char	*n_copy(char *copy, ssize_t count, char *return_word)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = cut_word(copy, count, return_word);
	copy_new = malloc(sizeof(char) * (count - i) + 1);
	if (!copy_new)
		return (NULL);
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

char	*get_next_line(int fd)
{
	char	*buf;
	char	*copy;
	ssize_t	read_file;
	ssize_t	count_all;
	char	*return_word;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE + 1] = '\0';
	while (1)
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if (read_file < 0)
			return (NULL);
		if (read_file == 0)
			break ;
		copy = buf_insert(buf, count_all, copy);
		count_all = read_file + count_all;
	}
	return_word = NULL;
	copy = n_copy(char *copy, ssize_t count, char *return_word);
	return (return_word);
}
