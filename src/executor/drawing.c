/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:25:09 by adrherna          #+#    #+#             */
/*   Updated: 2024/12/11 16:16:01 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	tile_draw(t_map_data *map, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(map->mlx, image, x * TILE, y * TILE) == -1)
		return (-1);
	return (0);
}

void	draw_m(t_map_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_array[y] != NULL)
	{
		x = 0;
		while (map->map_array[y][x] != '\0')
		{
			tile_draw(map, map->floor, x, y);
			if (map->map_array[y][x] == '1')
				tile_draw(map, map->wall, x, y);
			else if (map->map_array[y][x] == 'C')
				tile_draw(map, map->coll, x, y);
			else if (map->map_array[y][x] == 'E')
				tile_draw(map, map->exit, x, y);
			x++;
		}
		y++;
	}
}

void	redo_tile(t_map_data *map, int x, int y)
{
	char		curr_type;
	mlx_image_t	*texture;

	curr_type = map->map_array[y][x];
	if (curr_type == 'E')
		texture = map->exit;
	else
		texture = map->floor;
	tile_draw(map, map->floor, x, y);
	tile_draw(map, texture, x, y);
}

void	draw_p(t_map_data *map)
{
	redo_tile(map, map->x, map->y);
	tile_draw(map, map->player, map->x, map->y);
}
