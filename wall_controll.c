/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_controll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:57:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 16:40:14 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



void	wall_control(t_map *map, int y, int x)
{
	int	x_count;

	while (map->map_line[y])
	{
		x_count = ((int)ft_strlen(map->map_line[y]));
		if (y == 0 || y == map->map_y_line - 1)
		{
			x = 0;
			while (x < x_count - 2)
			{
				if (map->map_line[y][x] != WALL)
					error_and_free(map->map_line, "WALL ERROR1");
				x++;
			}	
		}
		else
		{
			if (map->map_line[y][0] != WALL)
				error_and_free(map->map_line, "WALL ERROR2");
			if (map->map_line[y][x_count - 3] != WALL)
				error_and_free(map->map_line, "WALL ERROR3");
		}
		y++;
	}
}

void	character_wall_control(t_map *map, int y, int x)
{
	while (map->map_line[y])
	{
		x = 0;
		while (x < ((int)ft_strlen(map->map_line[y])-2) && \
		map->map_line[y][x] != '\n' && map->map_line[y][x] != '\0')
		{

			if (ft_strchr(MAP_CHAR, map->map_line[y][x]) != NULL)
				x++;
			else
				error_and_free(map->map_line, "MAP CHAR ERROR");
		}
		y++;
	}
}


void	check_walls_and_character(t_map *map)
{
	wall_control(map, 0, 0);
	character_wall_control(map, 0, 0);
}