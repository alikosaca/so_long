/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:56:40 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 17:19:53 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_name_and_ac_control(char *file_name, int ac)
{
	int		file_name_len;

	file_name = ft_strchr(file_name, '/');
	file_name++;
	file_name_len = (int)ft_strlen(file_name);
	if (ac != 2)
		error("ac number is wrong");
	if (file_name[file_name_len - 4] == '.' && \
		file_name[file_name_len - 3] == 'b' && \
		file_name[file_name_len - 2] == 'e' && \
		file_name[file_name_len - 1] == 'r' && \
		file_name_len >= 5)
		return ;
	error("file name is incorrect!");
}

void	map_control(t_map *map, t_player *player)
{
	rectangle_control(map);
	character_control(map, player);
	check_walls_and_character(map);
	check_valid_path(map, player);
	free_map(map->map_line);
}

void	map_init(t_map *map, t_player *player, char *file_name)
{
	t_data	data;

	data.map = map;
	data.player = player;
	map_read_control(map, file_name);
	init_mlx(map);
	create_xpm(map);
	view_window(map);
	render_map(map, player, 0, 0);
	mlx_key_hook(map->mlx_win, key_hook, &data);
	mlx_hook(map->mlx_win, 17, 1L << 17, close_game, map);
	mlx_loop(map->mlx);
}

int	main(int ac, char *av[])
{
	t_map *const	map = &(t_map){0};
	t_player *const	player = &(t_player){0};

	file_name_and_ac_control(av[1], ac);
	map_read_control(map, av[1]);
	map_control(map, player);
	map_init(map, player, av[1]);
	return (0);
}
