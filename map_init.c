/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:39:20 by root              #+#    #+#             */
/*   Updated: 2025/03/11 17:40:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_xpm(t_map *map)
{
	int x;
	int y;
	map->img_coin = mlx_xpm_file_to_image(map->mlx, "./img/coin.xpm", &x, &y);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "./img/exit_1.xpm", &x, &y);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm", &x, &y);
	map->img_space = mlx_xpm_file_to_image(map->mlx, "./img/space.xpm", &x, &y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &x, &y);
	if (!map->img_coin || !map->img_exit \
		|| !map->img_player || !map->img_space \
		|| !map->img_wall)
		{
			error_mlx(map, "xpm okuma hatası:/");
		}
}

void	window_Image(t_map *map, t_player *player)
{
	int	x;
	int y;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] && map->map_line[y][x] != '\n')
		{
			if (map->map_line[y][x] == 'E')
				ft_put(map, map->img_exit, x, y);
			if (map->map_line[y][x] == 'C')
				ft_put(map, map->img_coin, x, y);
			if (map->map_line[y][x] == 'P')
				ft_put(map, map->img_player, player->x_location, player->y_location);
			if (map->map_line[y][x] == '0')
				ft_put(map, map->img_space, x, y);
			if (map->map_line[y][x] == '1')
				ft_put(map, map->img_wall, x, y);
			x++;
		}
	}	
}

void	put_Image(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, 64 * x, 64 * y);
}