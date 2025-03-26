/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:56:54 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 17:10:14 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangle_control(t_map *map)
{
	int	y_position;
	int	x_first;
	int	x_len;

	if (!map || !map->map_line || !map->map_line[0])
		return ;
	y_position = 0;
	x_first = (int)ft_strlen(map->map_line[0]);
	while (y_position < (map->map_y_line))
	{
		if (!map->map_line[y_position])
			break ;
		x_len = 0;
		while (map->map_line[y_position] && \
				map->map_line[y_position][x_len] && \
				map->map_line[y_position][x_len +1] != '\n' && \
				map->map_line[y_position][x_len] != '\0')
		{
			x_len++;
		}
		if (x_len != x_first -2)
			error_and_free(map->map_line, "the wall is faulty");
		y_position++;
	}
}

void	character_control(t_map *map, t_player *player)
{
	if (!map || !map->map_line || !player)
		return ;
	character_process_control(map, player, 0, 0);
	if (map->exit_count != 1)
		error_and_free(map->map_line, "EXIT COUNT WRONG");
	if (map->player_count != 1)
		error_and_free(map->map_line, "PLAYER EXIT COUNT WRONG");
	if (map->coin_count < 1)
		error_and_free(map->map_line, "COLLECTABLE EXIT COUNT WRONG");
}

void	character_process_control(t_map *map, t_player *player, int x, int y)
{
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] && map->map_line[y][x] != '\n' && \
				map->map_line[y][x] != '\0')
		{
			character_boost(map, player, x, y);
			x++;
		}
		y++;
	}	
}

void	character_boost(t_map *map, t_player *player, int x, int y)
{
	if (map->map_line[y][x] == DOOR)
	{
		player->e_y_loc = y;
		player->e_x_loc = x;
		map->exit_count++;
	}
	if (map->map_line[y][x] == COIN)
		map->coin_count++;
	if (map->map_line[y][x] == PLAYER)
	{
		player->p_y_loc = y;
		player->p_x_loc = x;
		map->player_count++;
	}
	if (map->map_line[y][x] == WALL)
		map->wall_count++;
}
