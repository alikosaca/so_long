	//int	x_len;
	// while (y_position < (map->map_y_line))
	// {
	// 	x_len = 0;
	// 	while (map->map_line[y_position] && \
	// 			map->map_line[y_position][x_len] != '\n' && \
	// 			x_len < (int)(ft_strlen(map->map_line[y_position])))
	// 	{
	// 		x_len++;
	// 	}
	// 	if (x_len != x_first -1)
	// 		error_and_free(map->map_line, "the wall is faulty");
	// 	y_position++;
	// }
	// if (new_x == player->e_x_location && new_y == player->e_y_location && \
	// 	player->coin_collected == map->coin_count)
	// {
	// 	ft_printf("Victory! \n Congratulations! Moves: %d\n", map->p_move_count);
	// 	close_game(map); 
	// }

// 	if (map->map_line[y][x] == 'P' || \
// 		map->map_line[y][x] == 'E' || \
// 		map->map_line[y][x] == 'C')
// 		put_value(map, player, x, y);


// void	put_value(t_map *map, t_player *player, int x, int y)
// {
// 	if (map->map_line[y][x] == 'P')
// 	{
// 		player->p_x_location = x;
// 		player->p_y_location = y;
// 	}
// 	else if (map->map_line[y][x] == 'E')
// 	{
// 		player->e_x_location = x;
// 		player->e_y_location = y;
// 	}
// 	else if (map->map_line[y][x] == 'C')
// 		map->coin_count++;
// }
//-------------------------

// rectangle_control- ikinci while 
// x_len < ((int)(ft_strlen(map->map_line[y_position]))))

//main deki fonksiyonalra gönderim
/*int main(int ac, char *av[])
{
	t_map *const map = &(t_map){0};
	t_player *const player = &(t_player){0};
		
	ft_printf("file_name... %d \n", ac);
	file_name_and_ac_control(av[1]);
	ft_printf("map_read...\n");
	map_read_control(map, av[1]);
	ft_printf("map_control...\n");
	map_control(map, &player);
	ft_printf("map_control okundu!\n");
	ft_printf("map_init...\n");
	map_init(map, &player, av[1]);

	return (0);
}
*/


//errors controll valid recursive
/*   if (y < 0 || x < 0 || !map->map_line[y] || map->map_line[y][x] == '\0' || 
        map->map_line[y][x] == WALL)*/