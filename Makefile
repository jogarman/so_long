NAME = so_long
LIBFT = ./libft/libft.a


CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror -g3
OBJ_MLX_FLAGS = -I/usr/include -Imlx_linux -O3
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o

# Depend on OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
#LIBS := -lm -lbsd -lX11 -lXext
	MLX_FLAGS := -lm -lbsd -lX11 -lXext
	MINILIB = ./minilib/minilibx-linux/libmlx_Linux.a
	MINILIBX = mlx_linux
#INCLUDES = -I/usr/include -I. -Iincludes/ -I$(MINILIBX) -I$(LIBFT)
	OBJ_MLX_FLAGS = -I/usr/include -I. -Iincludes/ -I$(MINILIBX) -I$(LIBFT)
endif
ifeq ($(UNAME_S), Darwin)
	echo "OS privative functions needed"
endif

GREEN= \033[32m
COLOR_RESET = \033[0m

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC = so_long.c \
\
src/map_is_ok/is_map_null.c src/map_is_ok/map_is_ok.c src/map_is_ok/no_strange_obj.c \
src/map_is_ok/ok_number_c_e_p.c src/map_is_ok/is_rectangular.c src/map_is_ok/wall_is_ok.c \
src/map_is_ok/no_empty_lines.c src/map_is_ok/flood_fill_ok.c src/map_is_ok/name_is_ok.c \
\
src/one_time_files/get_n_lines.c src/one_time_files/get_one_line_map.c   \
src/one_time_files/n_arguments_ok.c src/one_time_files/y_max_arr.c \
\
src/ft_open.c src/get_map.c src/get_obj_pos.c src/free_map.c 
# src/print_map.c 

all: $(NAME)
$(NAME): $(LIBFT) $(MINILIB) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN) so_long program created!$(COLOR_RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OBJ_MLX_FLAGS) -c $< -o $@


$(MINILIB):
	$(MAKE) -C ./minilib/minilibx-linux

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	@rm -f $(OBJ) $(NAME)
	$(MAKE) -C libft clean
# $(MAKE) -C minilib/minilibx-linux clean

fclean: clean
	@rm -f $(LIBFT)
	$(MAKE) -C libft fclean
	$(MAKE) -C minilib/minilibx-linux fclean

re: fclean all

g3:
	@gcc $(SRC) libft/*.c -g3 -Imlx -o so_long

.PHONY: all clean fclean re g3
