NAME = libft.a
SOURCES =	ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
       		ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
       		ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
	   		ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
	   		ft_strncmp.c \
			ft_memcmp.c \
			ft_strnstr.c \
	   		ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
       		ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
       		ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
       		ft_putendl_fd.c \
			ft_putnbr_fd.c \
			get_next_line.c \
			get_next_line_utils.c \

BONUS_SOURCES =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

BONUS_OBJS =$(BONUS_SOURCES:.c=.o)
OBJS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

bonus: $(BONUS_OBJS)
	ar -r $(NAME) $(BONUS_OBJS)

re: fclean all
