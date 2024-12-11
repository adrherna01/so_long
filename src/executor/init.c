/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:15:39 by adrherna          #+#    #+#             */
/*   Updated: 2024/12/11 16:10:27 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	init(t_map_data *map)
{
	map->mlx = mlx_init(TILE * map->first_row_len, TILE * map->rows,
			"My Game", false);
	if (!map->mlx)
	{
		ft_printf("Error:\nFailed to initialize MLX\n");
		return (-1);
	}
	if (init_textures(map) == -1)
	{
		ft_printf("Error:\nFailed to load textures\n");
		return (-1);
	}
	return (0);
}
