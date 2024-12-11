/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:44:11 by adrherna          #+#    #+#             */
/*   Updated: 2024/12/11 16:10:55 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map_data(t_map_data *map)
{
	size_t	i;

	i = 0;
	if (map != NULL)
	{
		if (map->map_array != NULL)
		{
			while (i < map->rows)
			{
				free(map->map_array[i]);
				free(map->map_cpy[i]);
				i++;
			}
			free(map->map_array);
			free(map->map_cpy);
		}
	}
	map->map_cpy = NULL;
	map->map_array = NULL;
	free(map);
}

int	map_malloc(const char *path, t_map_data *map)
{
	int		map_fd;
	char	*line;

	map->rows = 0;
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		map->rows++;
		free(line);
	}
	close(map_fd);
	map->map_array = malloc((map->rows + 1) * sizeof(char *));
	if (!map->map_array)
		return (-1);
	map->map_array[map->rows] = NULL;
	return (0);
}

int	open_file(char *path, t_map_data *map)
{
	int		map_fd;

	if (map_malloc(path, map))
		return (-1);
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
	{
		ft_printf("Error opening the file");
		return (-1);
	}
	return (map_fd);
}

int	map_reading(char *path, t_map_data *map)
{
	size_t		i;
	int			map_fd;
	char		*line;

	i = 0;
	map_fd = open_file(path, map);
	while (i < map->rows)
	{
		line = get_next_line(map_fd);
		map->map_array[i] = malloc(ft_strlen(line) + 1);
		if (!map->map_array[i])
		{
			free(line);
			close(map_fd);
			return (-1);
		}
		if (line[ft_strlen(line) - 1] == '\n')
			ft_strlcpy(map->map_array[i], line, ft_strlen(line));
		else
			ft_strlcpy(map->map_array[i], line, ft_strlen(line) + 1);
		free(line);
		i++;
	}
	close(map_fd);
	return (0);
}

int	full_map_check(t_map_data *map)
{
	if (wall_checking(map))
	{
		ft_putendl_fd("Error:\nWall Configuration", STDOUT_FILENO);
		return (-1);
	}
	if (row_len_checking(map))
	{
		ft_putendl_fd("Error:\nMap Not Rectangular", STDOUT_FILENO);
		return (-1);
	}
	if (char_checking(map))
	{
		ft_putendl_fd("Error:\nMissing or not valid Characthers in the Map",
			STDOUT_FILENO);
		return (-1);
	}
	char_count(map);
	if (map->num_exits != 1 || map->num_start_pos != 1 || map->num_coll < 1)
	{
		ft_putendl_fd("Error:\nNot Enough Required Characters", STDOUT_FILENO);
		return (-1);
	}
	return (0);
}
