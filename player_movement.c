/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:16:06 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/15 09:16:06 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	close_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_space);
	mlx_destroy_image(map->mlx, map->img_wall);
	mlx_destroy_image(map->mlx, map->img_player);
	mlx_destroy_image(map->mlx, map->img_exit);
	mlx_destroy_image(map->mlx, map->img_coin);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free_map(map);
	exit(EXIT_FAILURE);
}


int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		close_game(game);
	//...
	return (0);
}