#ifndef SO_LONG_H
# define SO_LONG_H

#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>


# define MAP_CHAR "01CEP"

typedef struct s_map
{
	char	**map_line;
    int		exit_x;
    int		exit_y;
	int		player_count;
	int		exit_count;
	int		coin_count;
	int		p_move_c;
	int		map_y_line;
	char	*f_name;
	void	*mlx;
	void	*mlx_win;
}               t_map;

typedef struct s_player
{
    int		x_location;
	int		y_location;
}               t_player;

typedef struct s_img
{
    void *img_player;
    int *img_width;
    int *img_height;
    void *img_wall;
    void *coin;
    void *img_door;
    
}               t_img;

//main.c
int		file_name_control(char *file_name);
int		map_control(t_map *map, t_player *player);


int		map_read_control(t_map *map, char *f_name); //?
//player_controll
void	dikdortgen_kontrol(t_map *map);
void	karakter_kontrol(t_map *map, t_player *player);
void	karakter_kontrol_islem(t_map *map, t_player *player, int x, int y);



//all_errors
void	error_dikdortgen(t_map *map);
void	error_map(t_map *map, char *message);
void	error_wall_and_character(t_map *map, int err_y, int err_x);
void	error_vail(t_map *map, char *message);


//wall_controll
void	check_walls_and_character(t_map *map);
void	wall_control(t_map *map, int y, int x);
void	character_control(t_map *map, int y, int x);

//map_read
int map_read_c(t_map *map, char *file_name);
void map_read_y(t_map *map, char *file_name);



//check_vaild_path
void	check_vaild_path(t_map *map, t_player *player);
void	vaild_recursive(t_map *map, int y, int x);
void	valid_control(t_map *map, int y, int x);
void	vail_coin_control(t_map *map);
void	vail_exit_control(t_map *map);

// free_map
void	free_map(t_map *map);



#endif