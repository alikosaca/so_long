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
	int		fd;
	int		i;
	char	*line;

	i = 0;
	map_read_y(map, file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_and_free(map->map_line, "Could not create map reading!");
	while (i < map->map_y_line)
	{
		line = get_next_line(fd);
		map->map_line[i] = ft_strtrim(line, "\n");
		free(line);
		if (!map->map_line[i])
		{
			while (i-- >= 0)
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
	int	len_y;

	if (!map || !file_name)
		error("Invalid parameters!");
	len_y = map_read_y_len(file_name);
	map->map_line = malloc(sizeof(char *) * (len_y + 1));
	if (!map->map_line)
		error("Could not allocate memory");
	map->map_line[len_y] = NULL;
	map->map_y_line = len_y;
	if (map->map_y_line < 3)
		error_and_free(map->map_line, "map reading error!");
}

int	map_read_y_len(char *file_name)
{
	char	*line;
	int		fd;
	int		lines;

	lines = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines++;
		free(line);
	}
	return (lines);
}
