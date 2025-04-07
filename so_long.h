/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:14:08 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/27 10:14:08 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define BACK 65364
# define RIGHT 65363

# define MAP_CHAR "01CEP"

# define WALL '1'
# define SPACE '0'
# define PLAYER 'P'
# define COIN 'C'
# define DOOR 'E'

typedef struct s_map
{
	char	**map_line;
	char	*f_name;
	int		player_count;
	int		wall_count;
	int		exit_count;
	int		coin_count;
	int		p_move_count;
	int		map_y_line;
	void	*mlx;
	void	*mlx_win;
	void	*img_player;
	void	*img_wall;
	void	*img_exit1;
	void	*img_exit2;
	void	*img_space;
	void	*img_coin;
}				t_map;

typedef struct s_player
{
	int		p_x_loc;
	int		p_y_loc;
	int		e_x_loc;
	int		e_y_loc;
	int		coin_collected;
}				t_player;

typedef struct s_data
{
	t_map		*map;
	t_player	*player;
}				t_data;

void	file_name_and_ac_control(char *file_name, int ac);
void	map_control(t_map *map, t_player *player);
void	map_init(t_map *map, t_player *player, char *file_name);

void	character_process_control(t_map *map, t_player *player, int x, int y);
void	character_control(t_map *map, t_player *player);
void	rectangle_control(t_map *map);
void	character_boost(t_map *map, t_player *player, int x, int y);

void	error_view_window(t_map *map);
void	error_and_free(char **map, char *message);
void	error(char *message);

void	check_walls_and_character(t_map *map);
void	wall_control(t_map *map, int y, int x, int x_count);
void	character_wall_control(t_map *map, int y, int x);

void	map_read_control(t_map *map, char *file_name);
void	map_read_y(t_map *map, char *file_name);
void	map_x_control(t_map *map, int i);
int		map_read_y_len(char *file_name);

void	check_valid_path(t_map *map, t_player *player);
void	valid_recursive(t_map *map, int y, int x);
void	valid_control(t_map *map, int y, int x);
void	valid_coin_control(t_map *map);
void	valid_exit_control(t_map *map);

void	free_map(char **map);

void	put_image(t_map *map, void *img, int x, int y);
void	put_value(t_map *map, t_player *player, int x, int y);
void	render_map(t_map *map, t_player *player, int x, int y);
void	create_xpm(t_map *map);
void	view_window(t_map *map);
void	init_mlx(t_map *map);

void	move_player(t_map *map, t_player *player, int new_y, int new_x);
void	door_move(t_map *map, t_player *player);
int		close_game(t_map *map);
int		key_hook(int keycode, t_data *data);
void	new_location(t_map *map, t_player *player, int new_y, int new_x);

#endif
