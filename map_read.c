/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:08:51 by root              #+#    #+#             */
/*   Updated: 2025/03/11 15:08:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_read_control(t_map *map, char *file_name)
{
    int fd;
    int i;

    i = 0;
    map_read_y(map, file_name);
    if (!(map->map_line) || map->map_y_line <= 0)
    {
        map->map_line = NULL;
        return (1);
    }

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        free(map->map_line);
        return(1);
    }
    while (map->map_y_line > i)
        map->map_line[i++] = get_next_line(fd);
    close(fd);
    return (0);
}



void    map_read_y(t_map *map, char *file_name)
{
    int fd;
    int len_y;
    char read_map;
    fd = open(file_name, O_RDONLY);
    len_y = 0;
    if (!fd)
    {
        map->map_y_line = 0;
        return ;
    }
    while (read(fd, &read_map, 1))
    {
        if (read_map == '\n')
            len_y++;
    }
    len_y++;
    close(fd);
    map->map_line = malloc(sizeof(char *) * len_y + 1);
    if (!map->map_line)
        return ;
    map->map_line[len_y] = NULL;
    map->map_y_line = len_y; 
    
}
