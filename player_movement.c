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
		//put_Image(map, map->img_space, new_x, new_y);
	}

	map->map_line[player->p_y_location][player->p_x_location] = SPACE;
	map->map_line[new_y][new_x] = PLAYER;
	put_Image(map, map->img_space, player->p_x_location, player->p_y_location);
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
	
	put_Image(map, map->img_player, new_x, new_y);
}

void	close_game(t_map *map)
{
    if (map->img_player)
        mlx_destroy_image(map->mlx, map->img_player);
    if (map->img_coin)
        mlx_destroy_image(map->mlx, map->img_coin);
    if (map->img_exit)
        mlx_destroy_image(map->mlx, map->img_exit);
    if (map->img_space)
        mlx_destroy_image(map->mlx, map->img_space);
    if (map->img_wall)
        mlx_destroy_image(map->mlx, map->img_wall);
    if (map->mlx_win)
        mlx_destroy_window(map->mlx, map->mlx_win);
    free_map(map->map_line);
    mlx_destroy_display(map->mlx);
    free(map->mlx);
    exit(EXIT_SUCCESS);
}


int	key_hook(int keycode, t_data *data)
{
    t_map *map = data->map;
    t_player *player = data->player;
    
    if (keycode == ESC)
        close_game(map);
    else if (keycode == W || keycode == UP)
        move_player(map, player, player->p_y_location - 1, player->p_x_location);
    else if (keycode == A || keycode == LEFT)
        move_player(map, player, player->p_y_location, player->p_x_location - 1);
    else if (keycode == S || keycode == BACK)
        move_player(map, player, player->p_y_location + 1, player->p_x_location);
    else if (keycode == D || keycode == RIGHT)
        move_player(map, player, player->p_y_location, player->p_x_location + 1);
    return (0);
}