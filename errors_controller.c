/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:56:11 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 16:34:08 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	error(char *message)
{
	ft_printf("Ups! %s \n", message);
	exit(EXIT_FAILURE);
}
void	error_and_free(char **map, char *message)
{
	ft_printf("Ups! %s \n", message);
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
	free_map(map->map_line);
	exit(EXIT_FAILURE);
}
