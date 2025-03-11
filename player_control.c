#include "so_long.h"


void	dikdortgen_kontrol(t_map *map)
{
	int	y_position;
	int	x_len;
	int x_first;

	y_position = 0;
	x_first = (int)ft_strlen(map->map_line[y_position]);
	while (y_position < (map->map_y_line))
	{
		x_len = 0;
		while (map->map_line[y_position] && \
				map->map_line[y_position][x_len] != '\n' && \
				x_len < (int)(ft_strlen(map->map_line[y_position])))
		{
			x_len++;
		}
		if (x_len != x_first -1)
		{
			error_dikdortgen(map);
		}
		y_position++;
	}
}

void	karakter_kontrol(t_map *map, t_player *player)
{
	karakter_kontrol_islem(map, player, 0, 0);
	if (map->exit_count != 1)
		error_map(map, "ÇIKIŞ");
	if (map->coin_count != 1)
		error_map(map, "TOPLANABILIR");
	if (map->player_count != 1)
		error_map(map, "OYUNCU");
}

void	karakter_kontrol_islem(t_map *map, t_player *player, int x, int y)
{
	map->player_count = 0;
	map->coin_count = 0;
	map->exit_count = 0;
	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x])
		{
			if (map->map_line[y][x] == 'E')
				map->exit_count++;
			else if (map->map_line[y][x] == 'C')
				map->coin_count++;
			if (map->map_line[y][x] == 'P')
			{
				player->y_location = y;
				player->x_location = x;
				map->player_count++;
			}
		}
		y++;
	}	
}
