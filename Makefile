CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_LIB = -lmlx -lm -L ./mlx -framework OpenGL -framework Appkit

NAME = fdf
NAME_BONUS = fdf_bonus

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

HEADERS = ./includes
HEADERS_BONUS = ./includes_bonus

SRCS = srcs/fdf.c \
		srcs/draw_img.c \
		srcs/draw_img_utils.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/input_handler.c \
		srcs/read_map.c \
		srcs/read_map_utils.c \
		srcs/set_coordinate.c \
		srcs/set_coordinate_utils.c \
		srcs/split.c

SRCS_BONUS = srcs_bonus/fdf_bonus.c \
		srcs_bonus/draw_img_bonus.c \
		srcs_bonus/draw_img_utils_bonus.c \
		srcs_bonus/get_next_line_bonus.c \
		srcs_bonus/get_next_line_utils_bonus.c \
		srcs_bonus/input_handler_bonus.c \
		srcs_bonus/read_map_bonus.c \
		srcs_bonus/read_map_utils_bonus.c \
		srcs_bonus/set_coordinate_bonus.c \
		srcs_bonus/set_coordinate_utils_bonus.c \
		srcs_bonus/split_bonus.c

DYLIB = libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_LIB) -I$(HEADERS) $(OBJS) -o $(NAME)
	cp mlx/$(DYLIB) ./$(DYLIB)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(MLX_LIB) -I$(HEADERS_BONUS) $(OBJS_BONUS) -o $(NAME_BONUS)
	cp mlx/$(DYLIB) ./$(DYLIB)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADERS) -I$(HEADERS_BONUS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -f $(DYLIB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
