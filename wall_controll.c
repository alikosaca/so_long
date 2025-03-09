/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_controll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:43:36 by root              #+#    #+#             */
/*   Updated: 2025/03/09 19:19:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	duvar_kontrol(t_map *map)
{
	wall_first_end(map);
}

void	wall_first_end(t_map *map)
{
	int	y;
	int	x;

	while (map->map_line[y])
	{
		if (y == 0 || y == map->map_y_line)
		{
			x = 0;
			while (map->map_line[y][x])
			{
				if (map->map_line[y][x] != '1')
					error_wall(map, x, y);
				x++;
			}	
		}
		y++;
	}
	
	
}
