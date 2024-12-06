/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:26:02 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/09 11:20:02 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

bool	load_texture(mlx_t *mlx, const char *path, mlx_image_t **texture)
{
	mlx_texture_t	*temp_texture;

	temp_texture = mlx_load_png(path);
	if (!temp_texture)
		return (false);
	*texture = mlx_texture_to_image(mlx, temp_texture);
	if (!*texture)
		return (false);
	mlx_delete_texture(temp_texture);
	return (true);
}

int	init_textures(t_map_data *map)
{
	if (!load_texture(map->mlx, PLAYER, &map->player))
		return (-1);
	if (!load_texture(map->mlx, WALL, &map->wall))
		return (-1);
	if (!load_texture(map->mlx, FLOOR, &map->floor))
		return (-1);
	if (!load_texture(map->mlx, EXIT, &map->exit))
		return (-1);
	if (!load_texture(map->mlx, COLLECTABLE, &map->coll))
		return (-1);
	return (0);
}

void	var_init(t_map_data *map)
{
	map->map_array = NULL;
	map->map_cpy = NULL;
	map->mlx = NULL;
	map->player = NULL;
	map->floor = NULL;
	map->wall = NULL;
	map->exit = NULL;
	map->coll = NULL;
	map->move_count = 0;
	map->first_row_len = 0;
	map->rows = 0;
	map->num_coll = 0;
	map->num_exits = 0;
	map->num_start_pos = 0;
	map->x = 0;
	map->y = 0;
}

int	map_proccess(t_map_data *map, char *path)
{
	var_init(map);
	if (ext_check(path))
	{
		ft_printf("File extension not valid, should be: .ber.\n");
		return (-1);
	}
	if (map_reading(path, map) || full_map_check(map))
	{
		ft_printf("Map not valid\n");
		map_dup(map);
		return (-1);
	}
	map_dup(map);
	flood_fill(map, map->x, map->y);
	if (check_flood_fill(map))
	{
		ft_printf("Error:\nMap path is wrong\n");
		return (-1);
	}
	return (0);
}
