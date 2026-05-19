/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:11:44 by ayanaga           #+#    #+#             */
/*   Updated: 2026/05/19 22:59:47 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char	*buf;
	ssize_t	read_file;
	ssize_t stash;

	read_file = malloc(BUFFER_SIZE + 1);
	if (!read_file)
		return (NULL);
	read_file = read(fd, buf, BUFFER_SIZE);
	read_file[BUFFER_SIZE + 1] = '\0';
	while (read_file[i] != '\0')
	{
		while (read_file[i] != '\n')
			stash[i] = read_file[i];
		if (read_file[i] == '\n')
		{
			while (j);
		}

	}
}
