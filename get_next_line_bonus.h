/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:48:37 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/04 08:07:34 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
char	*free_null(char *s);
char	*buf_insert(char *buf, ssize_t count, char *copy, ssize_t read_file);
int		cut_word(char *copy, char **return_word);
char	*get_file_and_copy(int fd, char *buf, char *copy, ssize_t read_file);
char	*n_copy(char *copy, ssize_t count, char **return_word);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);

#endif
