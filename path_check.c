/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:11:53 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/06 14:47:46 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <stdlib.h>

int	map_dup(t_map_data *map)
{
	int	i;

	map->map_cpy = malloc((map->rows + 1) * sizeof(char *));
	i = 0;
	while (map->map_array[i] != NULL)
	{
		map->map_cpy[i] = ft_strdup(map->map_array[i]);
		if (!map->map_cpy[i])
			return (-1);
		i++;
	}
	map->map_cpy[map->rows] = NULL;
	return (0);
}

bool	check_fill(char tile)
{
	int	i;

	i = 0;
	while (TAR_CHR[i] != '\0')
	{
		if (tile == TAR_CHR[i])
			return (true);
		i++;
	}
	return (false);
}

void	flood_fill(t_map_data *map, int x, int y)
{
	if (x < 0 || x >= (int)map->first_row_len || y < 0 || y >= (int)map->rows
		|| !check_fill(map->map_cpy[y][x]))
	{
		return ;
	}
	map->map_cpy[y][x] = FILL_CHR;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_flood_fill(t_map_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_cpy[y] != NULL)
	{
		x = 0;
		while (map->map_cpy[y][x])
		{
			if (map->map_cpy[y][x] == 'E' || map->map_cpy[y][x] == 'C')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
