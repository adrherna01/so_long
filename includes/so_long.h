/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:18 by adrherna          #+#    #+#             */
/*   Updated: 2024/12/11 16:21:41 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define FILE_END ".ber"
# define TAR_CHR "0PEC"
# define FILL_CHR 'F'
# define TILE 50
# define PLAYER "./images/player.png"
# define WALL "./images/wall.png"
# define EXIT "./images/exit.png"
# define FLOOR "./images/floor.png"
# define COLLECTABLE "./images/collectable.png"

typedef struct s_map_data {
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*coll;
	size_t		first_row_len;
	size_t		rows;
	char		**map_array;
	char		**map_cpy;
	int			num_coll;
	int			num_exits;
	int			num_start_pos;
	int			move_count;
	int			x;
	int			y;
}	t_map_data;

////// src/parser/map_checking.c:

int	wall_checking(t_map_data *map);
int	row_len_checking(t_map_data *map);
int	char_checking(t_map_data *map);
int	char_count(t_map_data *map);
int	ext_check(char *file);

////// src/parser/map_checking.c:

int	map_dup(t_map_data *map);
bool	check_fill(char tile);
void	flood_fill(t_map_data *map, int x, int y);
int	check_flood_fill(t_map_data *map);



////// src/executor/drawing.c:

int	tile_draw(t_map_data *map, mlx_image_t *image, int x, int y);
void	draw_m(t_map_data *map);
void	redo_tile(t_map_data *map, int x, int y);
void	draw_p(t_map_data *map);

////// src/executor/init.c:

int	init(t_map_data *map);



////// src/executor/so_long_utils.c:

void	free_map_data(t_map_data *map);
int	map_malloc(const char *path, t_map_data *map);
int	open_file(char *path, t_map_data *map);
int	map_reading(char *path, t_map_data *map);
int	full_map_check(t_map_data *map);

////// src/executor/so_long_utils_2.c:

bool	load_texture(mlx_t *mlx, const char *path, mlx_image_t **texture);
int	init_textures(t_map_data *map);
void	var_init(t_map_data *map);
int	map_proccess(t_map_data *map, char *path);

#endif
