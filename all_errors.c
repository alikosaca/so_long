/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:07:01 akosaca              #+#    #+#             */
/*   Updated: 2025/03/09 16:07:11 akosaca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_dikdortgen(t_map *map)
{
	ft_printf("Ups! dikdortgen degil!\n");
	free_map(map);
	exit(EXIT_FAILURE);
}
void	error_map(t_map *map, char *message)
{
	ft_printf("Ups! %s sayısı 1 değildir \n", message);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	error_wall(t_map *map, int err_y, int err_x)
{
	ft_printf("Ups! %d. satun, %d. satırda duvar hatası var!", err_y, err_x);
}