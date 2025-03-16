#include "so_long.h"

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y <= map->map_y_line)
		free(map->map_line[y++]);
}
