/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:35:35 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/09 23:13:07 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*free_null(char *s);
char	*buf_insert(char *buf, ssize_t count, char *copy, ssize_t read_file);
int		cut_word(char *copy, char **return_word);
char	*get_file_and_copy(int fd, char *buf, char *copy, ssize_t read_file);

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*n_copy(char *copy, ssize_t count, char **return_word);

#endif
