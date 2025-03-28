NAME      = so_long
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
RM		  = rm -f
MLX_PATH  = minilibx-linux
MLX_REPO  = https://github.com/42Paris/minilibx-linux.git
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11
LIBFT		= libft/libft.a

SRCS		= check_valid_path.c \
			errors_controller.c \
			free.c \
			main.c \
			map_init.c \
			map_read.c \
			player_control.c \
			player_movement.c \
			wall_controll.c

OBJS		= $(SRCS:.c=.o)

all: $(MLX_PATH)/libmlx.a $(LIBFT) $(NAME)

$(MLX_PATH):
	git clone $(MLX_REPO)

$(MLX_PATH)/libmlx.a: $(MLX_PATH)
	make -C $(MLX_PATH)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(MLX_PATH)/libmlx.a $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@if [ -d "$(MLX_PATH)" ]; then \
		make -C $(MLX_PATH) clean; \
	fi
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
