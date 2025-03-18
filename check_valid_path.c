/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:56:18 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 17:30:30 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_exit_control(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] && map->map_line[y][x] != DOOR)
			x++;
		if (map->map_line[y][x] == DOOR)
		{
			if (map->map_line[y][x+1] != PLAYER || \
				map->map_line[y][x-1] != PLAYER || \
				map->map_line[y+1][x] != PLAYER || \
				map->map_line[y-1][x] != PLAYER)
				error_and_free(map->map_line, "ERROR DOOR");
			else
				return ;
		}
		y++;
	}
}

void	valid_coin_control(t_map *map)
{
	ft_printf("pittik\n");
	int y;
	int x;
	int x_count;

	y = 0;
	x_count = (int)ft_strlen(map->map_line[y])-2;
	ft_printf("%dcheck_valid--------\n", x_count);
	while (map->map_line[y])
	{
		x = 0;
		while (x <= x_count && map->map_line[y][x] != COIN)
			x++;
		if (map->map_line[y][x] == COIN)
			error_and_free(map->map_line, "ERROR COIN");
		y++;
	}
}

void	valid_control(t_map *map, int y, int x)
{
	if (map->map_line[y][x] == SPACE || map->map_line[y][x] == COIN)
	{
		map->map_line[y][x] = PLAYER;
		int i = -1;
		while (map->map_line[++i])
			ft_printf("map[%d]: %s\n", y, map->map_line[i]);
		valid_recursive(map, y, x);
	}
}

void	valid_recursive(t_map *map, int y, int x)
{
	ft_printf("valid girdim\n");
	ft_printf("y: %d, x: %d\n", y, x);

	if (y < 0 || x < 0 || !map->map_line[y] || map->map_line[y][x] == '\0' || 
		map->map_line[y][x] == WALL)
		return;
	ft_printf("if sonrasi\n");
	valid_control(map, y, x+1);
	valid_control(map, y, x-1);
	valid_control(map, y+1, x);
	valid_control(map, y-1, x);
}

void	check_valid_path(t_map *map, t_player *player)
{
	valid_recursive(map, player->p_y_loc, player->p_x_loc);
	valid_coin_control(map);
	valid_exit_control(map);
}
