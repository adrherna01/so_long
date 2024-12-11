/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:07:36 by adrherna          #+#    #+#             */
/*   Updated: 2024/01/10 14:43:28 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_initialize_line(char **line)
{
	if (*line == NULL)
	{
		*line = (char *)malloc(1);
		if (!*line)
		{
			return (-1);
		}
		*line[0] = '\0';
		return (1);
	}
	return (0);
}

char	*handle_new_line(char **line)
{
	char	*new_line;
	char	*temp;
	int		i;

	i = 0;
	while ((*line)[i] != 0)
	{
		if ((*line)[i] == '\n')
		{
			new_line = ft_substr(*line, 0, i + 1);
			temp = ft_substr(*line, i + 1, ft_strlen(*line) - i);
			free(*line);
			*line = temp;
			return (new_line);
		}
		i++;
	}
	return (NULL);
}

int	ft_handle_readed(char **line, char *buffer, ssize_t readed_bytes)
{
	char	*temp;

	if (readed_bytes < 0 || (readed_bytes == 0 && ft_strlen(*line) == 0))
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	else if (readed_bytes != 0)
	{
		temp = ft_strjoin(*line, buffer);
		if (!temp)
		{
			free(*line);
			*line = NULL;
			return (-1);
		}
		free(*line);
		*line = temp;
	}
	return (1);
}

char	*handle_no_nl(char **line, ssize_t readed_bytes)
{
	char	*temp;

	if (readed_bytes == 0 && ft_strlen(*line) != 0)
	{
		temp = ft_strdup(*line);
		free(*line);
		*line = NULL;
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*new_line;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		readed_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (line == NULL)
			if (ft_initialize_line(&line) < 0)
				return (NULL);
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (ft_handle_error(&line, readed_bytes) < 0)
			return (NULL);
		buffer[readed_bytes] = '\0';
		if (ft_handle_readed(&line, buffer, readed_bytes) <= 0)
			return (NULL);
		new_line = handle_new_line(&line);
		if (new_line != NULL)
			return (new_line);
		new_line = handle_no_nl(&line, readed_bytes);
		if (new_line != NULL)
			return (new_line);
	}
}
