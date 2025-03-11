/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_controll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:43:36 by root              #+#    #+#             */
/*   Updated: 2025/03/11 14:50:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	wall_control(t_map *map, int y, int x)
{
	int	x_count;

	while (map->map_line[y])
	{
		x_count = (int)ft_strlen(map->map_line[y]);
		if (y == 0 || y == map->map_y_line - 1)
		{
			x = 0;
			while (x < x_count - 1)
			{
				if (map->map_line[y][x] != '1')
					error_wall_and_character(map, y, x);
				x++;
			}	
		}
		else
		{
			if (map->map_line[y][0] != '1')
				error_wall_and_character(map, y, 0);
			if (map->map_line[y][x_count - 2] != '1')
				error_wall_and_character(map, y, x_count - 2);
		}
		y++;
	}
}

void	character_control(t_map *map, int y, int x)
{
	int i = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] != '\n' && map->map_line[y][x] != '\0')
		{
			if (ft_strchr("01ECP", map->map_line[y][x]))
				x++;
			else
				error_wall_and_character(map, y, x);
		}
		y++;
	}
}


void	check_walls_and_character(t_map *map)
{
	wall_control(map, 0, 0);
	character_control(map, 0, 0);
	
}