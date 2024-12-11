/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:07:33 by adrherna          #+#    #+#             */
/*   Updated: 2023/11/08 10:15:19 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len - start;
	if (start + len > s_len)
		len -= 1;
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	cpy = (char *)malloc(len * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str != NULL)
	{
		while (*s1 != 0)
		{
			new_str[i] = *s1;
			s1++;
			i++;
		}
		while (*s2 != 0)
		{
			new_str[i] = *s2;
			s2++;
			i++;
		}
		new_str[i] = 0;
	}
	else
		return (NULL);
	return (new_str);
}

int	ft_handle_error(char **line, ssize_t readed_bytes)
{
	if (readed_bytes < 0)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	return (0);
}
