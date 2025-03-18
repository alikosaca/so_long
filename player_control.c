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
	int x_first;
	int	x_len;

	y_position = 0;
	x_first = (int)ft_strlen(map->map_line[y_position]);
	ft_printf("----player_control_1%d--------\n", x_first);
	while (y_position < (map->map_y_line))
	{
		x_len = 0;
		while (map->map_line[y_position] && \
				map->map_line[y_position][x_len+1] != '\n' && \
				x_len < ((int)(ft_strlen(map->map_line[y_position]))))
		{
			x_len++;
		}
		if (x_len != x_first -2)
		{
			ft_printf("x:%d y:%d  yx:%c x_first:%d \n", x_len, y_position, map->map_line[y_position][x_len], x_first);
			error_and_free(map->map_line, "the wall is faulty");
		}
		y_position++;
	}
}

void	character_control(t_map *map, t_player *player)
{
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
		while (map->map_line[y][x] != '\n' && map->map_line[y][x] != '\0')
		{
			if (map->map_line[y][x] == DOOR)
			{
				ft_printf("map[%d][%d]: E\n", y, x);
				player->e_y_loc = y;
				player->e_x_loc = x;
				map->exit_count++;
			}
			else if (map->map_line[y][x] == COIN)
			{
				map->coin_count++;
				ft_printf("para buldum, %d\n", map->coin_count);
			}
			else if (map->map_line[y][x] == PLAYER)
			{
				ft_printf("map[%d][%d]: P\n", y, x);
				player->p_y_loc = y;
				player->p_x_loc = x;
				map->player_count++;
			}
			else if (map->map_line[y][x] == WALL)
				map->wall_count++;
			x++;
		}
		y++;
	}	
}
