/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:33:35 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/15 08:56:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_mlx(t_map *map)
{
	ft_printf("Ups! MiniLibX failed to initialize:/\n");
	free_map(map);
	exit(EXIT_FAILURE);
}
void	error_view_window(t_map *map)
{
	ft_printf("Ups! Could not create window:/\n");
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
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free_map(map);
	exit(EXIT_FAILURE);
}
