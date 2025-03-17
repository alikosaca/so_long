NAME      = so_long
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
RM		  = rm -f
MLX_PATH  = minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11
LIBFT		= libft/libft.a
FT_PRINTF	= ft_printf/libftprintf.a

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

all: $(MLX_PATH)/libmlx.a $(LIBFT) $(FT_PRINTF) $(NAME)

$(MLX_PATH)/libmlx.a: $(MLX_PATH)
	make -C $(MLX_PATH)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(NAME): $(OBJS) $(MLX_PATH)/libmlx.a $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

clean:
	@if [ -d "$(MLX_PATH)" ]; then \
		make -C $(MLX_PATH) clean; \
	fi
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(FT_PRINTF)
	rm -f $(LIBFT)

re: fclean all
