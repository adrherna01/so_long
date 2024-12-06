/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:43:53 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/09 10:34:46 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <stddef.h>
#include <stdio.h>

int	wall_checking(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map->rows <= 2)
		return (-1);
	map->first_row_len = ft_strlen(map->map_array[0]);
	while (map->map_array[0][j] != '\0' &&
		map->map_array[map->rows - 1][j] != '\0')
	{
		if (map->map_array[0][j] != '1' ||
			map->map_array[map->rows - 1][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (map->map_array[i] != NULL)
	{
		if ((map->map_array[i][0] != '1') ||
			(map->map_array[i][map->first_row_len - 1] != '1'))
			return (-1);
		i++;
	}
	return (0);
}

int	row_len_checking(t_map_data *map)
{
	int	i;

	i = 0;
	while (map->map_array[i] != NULL)
	{
		if (ft_strlen(map->map_array[i]) != map->first_row_len)
			return (-1);
		i++;
	}
	return (0);
}

int	char_checking(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_array[i] != NULL)
	{
		j = 0;
		while (map->map_array[i][j] != '\0')
		{
			if (map->map_array[i][j] != '0' && map->map_array[i][j] != '1' &&
				map->map_array[i][j] != 'C' && map->map_array[i][j] != 'E' &&
					map->map_array[i][j] != 'P')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	char_count(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_array[i] != NULL)
	{
		j = 0;
		while (map->map_array[i][j] != '\0')
		{
			if (map->map_array[i][j] == 'E')
				map->num_exits += 1;
			if (map->map_array[i][j] == 'C')
				map->num_coll += 1;
			if (map->map_array[i][j] == 'P')
			{
				map->num_start_pos += 1;
				map->x = j;
				map->y = i;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ext_check(char *file)
{
	const char	*extension = FILE_END;
	size_t		file_len;
	size_t		start;

	file_len = strlen(file);
	start = file_len - ft_strlen(extension);
	if (file_len < strlen(extension))
		return (-1);
	while (file[start] != '\0')
	{
		if (file[start] != extension[start - file_len + strlen(extension)])
			return (-1);
		start++;
	}
	return (0);
}
