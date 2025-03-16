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

void	move_player(t_map *map, t_player *player, int new_y, int new_x)
{
	if (map->map_line[new_y][new_x] == '1')
		return ;
	if (map->map_line[new_y][new_x] == 'C')
	{
		player->coin_collected++;
		map->map_line[new_y][new_x] = '0';
		//put_Image(map, map->img_space, new_x, new_y);
	}

	map->map_line[player->p_y_location][player->p_x_location] = '0';
	map->map_line[new_y][new_x] = 'P';
	player->p_x_location = new_x;
	player->p_y_location = new_y;
	map->p_move_count++;
	ft_printf("Moves: %d\n", map->p_move_count);
	if (new_x == player->e_x_location && new_y == player->e_y_location && \
		player->coin_collected == map->coin_count)
	{
		ft_printf("Victory! \n Congratulations! Moves: %d\n", map->p_move_count);
		close_game(map); 
	}
	put_Image(map, map->img_space, player->p_x_location, player->p_y_location);
	put_Image(map, map->img_player, new_x, new_y);
}

void	close_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_space);
	mlx_destroy_image(map->mlx, map->img_wall);
	mlx_destroy_image(map->mlx, map->img_player);
	mlx_destroy_image(map->mlx, map->img_exit);
	mlx_destroy_image(map->mlx, map->img_coin);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	exit(EXIT_FAILURE);
}


int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_game(data->map);
	else if (keycode == W || keycode == UP)
		move_player(data->map, data->player, \
			 		data->player->p_y_location - 1, \
					data->player->p_x_location);
	return (0);
}