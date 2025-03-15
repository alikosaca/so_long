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

void    map_control(t_map	*map, t_player *player)
{
	dikdortgen_kontrol(map);
	karakter_kontrol(map, player);
    check_walls_and_character(map);
    check_vaild_path(map, player);
	free_map(map);
}

void    map_init(t_map *map, t_player *player, char *file_name)
{
    int x_px;
    int y_px;

    map_read_control(map, file_name);
    map->p_move_count = 0;
    init_mlx(map);
    create_xpm(map);
    view_window(map);
    render_map(map, player);
    mlx_key_hook(map->mlx_win, key_hook, map);
}

int main(int ac, char *av[])
{
    t_map map;
    t_player player;
    if (ac != 2)
    {
        ft_printf("Ups! Argüman sayısı hatalı:/");
        return (1);
    }
    if (file_name_control(av[1]))
    {
        ft_printf("Ups! Dosya Uzantısı Hatalı:/");
        return (1);
    }
    if (map_read_control(&map, av[1]))
    {
        ft_printf("Ups! Dosya okuma hatası:/");
        return (1);
    }
    map_control(&map, &player);
    map_init(&map, &player, av[1]);

    return (0);
}
