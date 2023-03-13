NAME = so_long
SRCS = map_info.c map_check.c utils.c main.c valid_path_check.c mlx_controler.c ft_itoa.c mlx_controler2.c ./SRC/get_next_line/libftgnl.a
LIBFT = libft.a
GNL_SRCS = ./SRC/get_next_line/libftgnl.a
MLX = ./SRC/mlx/libmlx.a
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit -L./SRC/mlx -lmlx

$(NAME): $(SRCS) $(MLX) $(GNL_SRCS)
		gcc $(CFLAGS) $(LFLAGS) $(GNL_SRCS) $(SRCS) -o $(NAME)

all: $(MLX) $(GNL_SRCS) $(NAME)


$(MLX):
	$(MAKE) -C ./SRC/mlx
$(GNL_SRCS):
	@make -C ./SRC/get_next_line

clean:
	@rm -rf ./SRC/mlx/*.o
	@rm -rf ./SRC/get_next_line/*.o

fclean: clean
	@rm -rf ./SRC/mlx/*.a
	@rm -rf ./SRC/get_next_line/*.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re