NAME = so_long

SRCS =	main.c					srcs/error_close.c		get_next_line.c \
		srcs/game.c				srcs/img_init.c			srcs/map_draw.c \
		srcs/map_validation.c	srcs/move_draw.c		srcs/string_put.c \
		srcs/map_parse.c

INCLUDE = include/so_long.h

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework Opengl -framework Appkit

HEADER = includes/so_long.h

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(MAKE) -C mlx
	$(MAKE) -C libft
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) ./libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C libft
	$(MAKE) clean -C mlx
	rm -rf $(NAME)

bonus : $(NAME)

re : fclean all

.PHONY: clean fclean re all