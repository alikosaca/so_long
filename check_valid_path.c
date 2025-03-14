/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:10:34 by root              #+#    #+#             */
/*   Updated: 2025/03/15 07:55:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vail_exit_control(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] != 'E')
			x++;
		if (map->map_line[y][x] == 'E')
		{
			if (map->map_line[y][x+1] != 'P' || \
				map->map_line[y][x-1] != 'P' || \
				map->map_line[y+1][x] != 'P' || \
				map->map_line[y-1][x] != 'P')
				error_vail(map, "Çıkış Kapısı");
			else
				return ;
		}
		y++;
	}
}

void	vail_coin_control(t_map *map)
{
	int y;
	int x;
	int x_count;

	y = 0;
	x_count = (int)ft_strlen(map->map_line[y]);
	while (map->map_line[y])
	{
		x = 0;
		while (x <= x_count && map->map_line[y][x] != 'C')
			x++;
		if (map->map_line[y][x] == 'C')
			error_vail(map, "Toplanabilir Eşya");
		y++;
	}
}

void	valid_control(t_map *map, int y, int x)
{
	if (map->map_line[y][x] == '0' || map->map_line[y][x] == 'C')
	{
		map->map_line[y][x] = 'P';
		vaild_recursive(map, y, x);
	}
}

void	vaild_recursive(t_map *map, int y, int x)
{
	vaild_recursive(map, y, x+1);
	vaild_recursive(map, y, x-1);
	vaild_recursive(map, y+1, x);
	vaild_recursive(map, y-1, x);
}

void	check_vaild_path(t_map *map, t_player *player)
{
	int	y;
	int	x;

	y = player->y_location;
	x = player->x_location;
	vaild_recursive(map, y, x);
	vail_coin_control(map);
	vail_exit_control(map);
}
