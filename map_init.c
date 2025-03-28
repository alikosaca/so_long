/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:56:44 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 16:34:29 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		error_and_free(map->map_line, "COULD NOT BE CREATED");
}

void	create_xpm(t_map *map)
{
	int	x;
	int	y;

	map->img_coin = mlx_xpm_file_to_image(map->mlx, "./textures/coin.xpm", \
											&x, &y);
	map->img_exit1 = mlx_xpm_file_to_image(map->mlx, "./textures/exit_1.xpm", \
											&x, &y);
	map->img_exit2 = mlx_xpm_file_to_image(map->mlx, "./textures/exit_2.xpm", \
											&x, &y);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "./textures/player.xpm", \
											&x, &y);
	map->img_space = mlx_xpm_file_to_image(map->mlx, "./textures/space.xpm", \
											&x, &y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./textures/wall.xpm", \
											&x, &y);
	if (!map->img_coin || !map->img_exit1 || !map->img_exit2 || \
		!map->img_player || !map->img_space || !map->img_wall)
	{
		ft_printf("Image/images could not be loaded!\n");
		close_game(map);
	}
}

void	view_window(t_map *map)
{
	int	x_px;
	int	y_px;

	x_px = ((int)ft_strlen(map->map_line[0])) * 64;
	y_px = map->map_y_line * 64;
	map->mlx_win = mlx_new_window(map->mlx, x_px, y_px, "so_long");
	if (!map->mlx || !map->mlx_win)
		error_view_window(map);
}

void	render_map(t_map *map, t_player *player, int x, int y)
{
	while (y < map->map_y_line)
	{
		x = 0;
		while (map->map_line[y][x] && map->map_line[y][x] != '\n' && \
				x < ((int)ft_strlen(map->map_line[0])))
		{
			if (map->map_line[y][x] == '0')
				put_image(map, map->img_space, x, y);
			if (map->map_line[y][x] == '1')
				put_image(map, map->img_wall, x, y);
			if (map->map_line[y][x] == 'C')
				put_image(map, map->img_coin, x, y);
			if (map->map_line[y][x] == 'E')
				put_image(map, map->img_exit1, x, y);
			if (map->map_line[y][x] == 'P')
				put_image(map, map->img_player, \
						player->p_x_loc, player->p_y_loc);
			x++;
		}
		y++;
	}
}

void	put_image(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, 64 * x, 64 * y);
}
