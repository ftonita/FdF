NAME = fdf

C = gcc

C_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	fdf.c arr_utils.c print_utils.c \
		map_info.c map_parse.c utils.c \
		map_utils.c print_line.c print_map.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(patsubst %.c,%.o,$(SRCS))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C mlx
	@make -C libft
	$(CC) $(OBJ) mlx/libmlx.a libft/libft.a $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@make -C libft clean

fclean : clean
	@rm -f $(NAME)
	@make -C mlx clean
	@make -C libft fclean

re : fclean all

.PHONY : all clean fclean re