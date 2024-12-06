/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:13:25 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/13 11:43:28 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

// void	leaks(void)
// {
// 	system("leaks so_long");
// }

// atexit(leaks);

void	ft_try_move(t_map_data *map, size_t next_x, size_t next_y)
{
	if (next_x < 0 || next_x >= map->first_row_len || next_y < 0
		|| next_y >= map->rows || map->map_array[next_y][next_x] == '1')
		return ;
	if (map->map_array[next_y][next_x] == 'C')
	{
		map->num_coll -= 1;
		map->map_array[next_y][next_x] = '0';
	}
	redo_tile(map, map->x, map->y);
	map->x = next_x;
	map->y = next_y;
	draw_p(map);
	map->move_count += 1;
	ft_printf("Move Count: %d\n", map->move_count);
	if (map->map_array[next_y][next_x] == 'E' && map->num_coll == 0)
	{
		ft_printf("Great Success\nTotal Moves: %d\n", map->move_count);
		mlx_terminate(map->mlx);
		exit(0);
	}
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_map_data	*map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx);
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			ft_try_move(map, map->x, map->y - 1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			ft_try_move(map, map->x, map->y + 1);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			ft_try_move(map, map->x - 1, map->y);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			ft_try_move(map, map->x + 1, map->y);
	}
}

int	main(int argc, char *argv[])
{
	t_map_data	*map;

	if (argc != 2)
	{
		ft_printf("Invalid number of arguments\nRequired: 2\n");
		return (-1);
	}
	map = malloc(sizeof(t_map_data));
	if (map_proccess(map, argv[1]))
	{
		free_map_data(map);
		return (-1);
	}
	if (init(map))
	{
		free_map_data(map);
		return (-1);
	}
	draw_m(map);
	draw_p(map);
	mlx_key_hook(map->mlx, ft_hook, map);
	mlx_loop(map->mlx);
	free_map_data(map);
	return (0);
}
