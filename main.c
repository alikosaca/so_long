/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:00:41 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/05 09:00:42 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int     file_name_control(char *file_name)
{
    size_t file_name_len;

    file_name_len =ft_strlen(file_name);

    if (file_name[file_name_len - 4] == '.' && \
        file_name[file_name_len - 3] == 'b' && \
        file_name[file_name_len - 2] == 'e' && \
        file_name[file_name_len - 1] == 'r' && \
        file_name_len >= 5)
    {
        return (0);
    }
    return (1);
}

void    map_control(t_map *map, t_player *player)
{
	Rectangle_Control(map);
	Character_Control(map, player);
    check_walls_and_character(map);
    check_valid_path(map, player);
	free_map(map);
}

void    map_init(t_map *map, t_player *player, char *file_name)
{
    t_data *data;
    int x_px;
    int y_px;

    data->map = &map;
    data->player = &player;
    map->p_move_count = 0;
    map->coin_count = 0;
    player->coin_collected = 0;
    map_read_control(map, file_name);
    init_mlx(map);
    create_xpm(map);
    view_window(map);
    render_map(map, player, 0 ,0);
    mlx_key_hook(map->mlx_win, key_hook, data);
}

int main(int ac, char *av[])
{
    t_map map;
    t_player player;

    if (ac != 2)
    {
        ft_printf("Ups! Incorrect number of arguments:/\n");
        return (1);
    }
    if (file_name_control(av[1]))
    {
        ft_printf("Ups! File Extension Incorrect:/\n");
        return (1);
    }
    if (map_read_control(&map, av[1]))
    {
        ft_printf("Ups! File reading error:/\n");
        return (1);
    }
    map_control(&map, &player);
    map_init(&map, &player, av[1]);

    return (0);
}
