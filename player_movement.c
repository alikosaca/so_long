/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:56:58 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 17:21:57 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map *map, t_player *player, int new_y, int new_x)
{
	if (map->map_line[new_y][new_x] == WALL)
		return ;
	if (map->map_line[new_y][new_x] == COIN)
	{
		player->coin_collected++;
		map->map_line[new_y][new_x] = SPACE;
	}
	if (map->map_line[new_y][new_x] == DOOR)
	{
		if (player->coin_collected != map->coin_count)
		{
			ft_printf("collected:%d, coin:%d \n", \
					player->coin_collected, map->coin_count);
			return ;
		}
		ft_printf("Victory!\nCongratulations! Moves: %d\n", map->p_move_count);
		close_game(map);
	}
	if (player->coin_collected == map->coin_count)
	{
		put_image(map, map->img_exit2, player->e_x_loc, player->e_y_loc);
	}
	map->p_move_count++;
	ft_printf("Moves: %d\n", map->p_move_count);
	new_location(map, player, new_y, new_x);
}

void	new_location(t_map *map, t_player *player, int new_y, int new_x)
{
	map->map_line[player->p_y_loc][player->p_x_loc] = SPACE;
	put_image(map, map->img_space, player->p_x_loc, player->p_y_loc);
	map->map_line[new_y][new_x] = PLAYER;
	put_image(map, map->img_player, new_x, new_y);
	player->p_x_loc = new_x;
	player->p_y_loc = new_y;
}

int	close_game(t_map *map)
{
	if (map->img_player)
		mlx_destroy_image(map->mlx, map->img_player);
	if (map->img_coin)
		mlx_destroy_image(map->mlx, map->img_coin);
	if (map->img_exit1)
		mlx_destroy_image(map->mlx, map->img_exit1);
	if (map->img_exit2)
		mlx_destroy_image(map->mlx, map->img_exit2);
	if (map->img_space)
		mlx_destroy_image(map->mlx, map->img_space);
	if (map->img_wall)
		mlx_destroy_image(map->mlx, map->img_wall);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->map_line)
		free_map(map->map_line);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	t_map		*map;
	t_player	*player;

	map = data->map;
	player = data->player;
	if (keycode == ESC)
		close_game(map);
	else if (keycode == W || keycode == UP)
		move_player(map, player, player->p_y_loc - 1, player->p_x_loc);
	else if (keycode == A || keycode == LEFT)
		move_player(map, player, player->p_y_loc, player->p_x_loc - 1);
	else if (keycode == S || keycode == BACK)
		move_player(map, player, player->p_y_loc + 1, player->p_x_loc);
	else if (keycode == D || keycode == RIGHT)
		move_player(map, player, player->p_y_loc, player->p_x_loc + 1);
	return (0);
}
