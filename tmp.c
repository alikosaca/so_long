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

	if (map->map_line[y][x] == 'P' || \
		map->map_line[y][x] == 'E' || \
		map->map_line[y][x] == 'C')
		put_value(map, player, x, y);


void	put_value(t_map *map, t_player *player, int x, int y)
{
	if (map->map_line[y][x] == 'P')
	{
		player->p_x_location = x;
		player->p_y_location = y;
	}
	else if (map->map_line[y][x] == 'E')
	{
		player->e_x_location = x;
		player->e_y_location = y;
	}
	else if (map->map_line[y][x] == 'C')
		map->coin_count++;
}
