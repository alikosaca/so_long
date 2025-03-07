


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
    int exit_x;
    int exit_y;
	int		e_count;
	int		p_count;
	int		c_count;
	int		p_move_c;
	int		map_y_line;
	char	*f_name;
	void	*mlx;
	void	*mlx_win;
}               t_map;

typedef struct s_player
{
    int		p_x;
	int		p_y;
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


int		file_control(int argc, char *argv);
int		map_read_c(t_map *map, char *f_name);
int		map_read_control(t_map *map, char *f_name);
void	map_read(t_map *map, char *f_name);
int		map_control(t_map *map);
int		rectangle_c(t_map *map);
void	char_control(t_map *map, int x, int y);
int		char_c(t_map *map);
int		wall_c(t_map *map);
int		wall_f_e(t_map *map, int y);
int		wall_middle(t_map *map, int y);
int		element_c(t_map *map);
void	free_map(t_map *map);
void	recursive_p(t_map *map, int y, int x);
int		valid_c(t_map *map);
int		coin_c(t_map *map);
int		exit_c(t_map *map);
int		map_init(t_map *map, char	*argc);
int		create_xpm(t_map *map);
int		win_put_img(t_map *map);
void	ft_put(t_map *map, void *img, int x, int y);
int		ft_exit(t_map *map);
int		ft_move(int key, t_map *map);
void	map_move(t_map *map, int x, int y);







#endif