/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:05:54 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/16 09:08:20 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	Rectangle_Control(t_map *map)
{
	int	y_position;
	int	x_len;
	int x_first;

	y_position = 0;
	x_first = (int)ft_strlen(map->map_line[y_position]);
	while (y_position < (map->map_y_line))
	{
		x_len = 0;
		while (map->map_line[y_position] && \
				map->map_line[y_position][x_len] != '\n' && \
				x_len < (int)(ft_strlen(map->map_line[y_position])))
		{
			x_len++;
		}
		if (x_len != x_first -1)
		{
			error_rectangle(map);
		}
		y_position++;
	}
}

void	Character_Control(t_map *map, t_player *player)
{
	Character_Process_Control(map, player, 0, 0);
	if (map->exit_count != 1)
		error_map(map, "EXIT");
	if (map->coin_count != 1)
		error_map(map, "COLLECTABLE");
	if (map->player_count != 1)
		error_map(map, "PLAYER");
}

void	Character_Process_Control(t_map *map, t_player *player, int x, int y)
{
	map->player_count = 0;
	map->coin_count = 0;
	map->exit_count = 0;
	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x])
		{
			if (map->map_line[y][x] == 'E')
				map->exit_count++;
			else if (map->map_line[y][x] == 'C')
				map->coin_count++;
			if (map->map_line[y][x] == 'P')
			{
				player->p_y_location = y;
				player->p_x_location = x;
				map->player_count++;
			}
		}
		y++;
	}	
}
