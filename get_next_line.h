/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:07:38 by adrherna          #+#    #+#             */
/*   Updated: 2023/11/08 10:15:31 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

char	*handle_new_line(char **line);

int		ft_initialize_line(char **line);

int		ft_handle_readed(char **line, char *buffer, ssize_t readed_bytes);

char	*handle_no_nl(char **line, ssize_t readed_bytes);

int		ft_handle_error(char **line, ssize_t readed_bytes);

#endif
