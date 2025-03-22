/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 06:56:50 by akosaca           #+#    #+#             */
/*   Updated: 2025-03-17 06:56:50 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	map_read_control(t_map *map, char *file_name)
{
	int fd;
	int i;

	i = 0;
	if (!map || !file_name)
		error("Invalid parameters!");
	
	map_read_y(map, file_name);
	
	if (!(map->map_line) || map->map_y_line <= 0)
		error_and_free(map->map_line, "map reading error!");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_and_free(map->map_line, "Could not create map reading!");
	while (i < map->map_y_line)
	{
		map->map_line[i] = get_next_line(fd);
		if (!map->map_line[i])
		{
			while (--i >= 0)
				free(map->map_line[i]);
			free(map->map_line);
			error("Failed to read map line!");
		}
		i++;
	}
	close(fd);
}


void	map_read_y(t_map *map, char *file_name)
{
	int fd;
	int len_y;
	char read_map;
	ssize_t read_result;

	fd = open(file_name, O_RDONLY);
	len_y = 0;
	if (fd < 0)
		error("Could not create map reading!");
	
	while ((read_result = read(fd, &read_map, 1)) > 0)
	{
		if (read_map == '\n')
			len_y++;
	}
	
	if (read_result < 0)
	{
		close(fd);
		error("Error reading file!");
	}
	
	len_y++;
	close(fd);
	
	map->map_line = malloc(sizeof(char *) * (len_y + 1));
	if (!map->map_line)
		error("Could not allocate memory");
	
	map->map_line[len_y] = NULL;
	map->map_y_line = len_y;
}
