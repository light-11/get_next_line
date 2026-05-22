/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:11:44 by ayanaga           #+#    #+#             */
/*   Updated: 2026/05/22 22:51:19 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*buf_insert(char *buf, ssize_t count, char *copy, ssize_t read_file)
{
	int		i;
	int		j;
	char	*copy_all;

	i = 0;
	j = 0;
	copy_all = malloc(sizeof(char) * (count + read_file + 1));
	if (!copy_all)
	{
		free(copy);
		return (NULL);
	}
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

static int	cut_word(char *copy, char **return_word)
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

static char	*n_copy(char *copy, ssize_t count, char **return_word)
{
	int		i;
	int		j;
	char	*copy_new;

	i = 0;
	j = 0;
	i = cut_word(copy, return_word);
	if (i == -1)
	{
		free(copy);
		return (NULL);
	}
	if (copy[i] == '\0')
	{
		free(copy);
		return (NULL);
	}
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
	char		*buf;
	static char	*copy;
	ssize_t		read_file;
	char		*return_word;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		if (read_file < 0)
		{
			free(buf);
			return (NULL);
		}
		if (read_file == 0)
			break ;
		buf[read_file] = '\0';
		if (copy)
			copy = buf_insert(buf, ft_strlen(copy), copy, read_file);
		else
			copy = buf_insert(buf, 0, copy, read_file);
		if (ft_strchr(copy, '\n'))
			break ;
	}
	if (!copy || copy[0] == '\0')
	{
		free(buf);
		free(copy);
		copy = NULL;
		return (NULL);
	}
	return_word = NULL;
	copy = n_copy(copy, ft_strlen(copy), &return_word);
	free(buf);
	return (return_word);
}
