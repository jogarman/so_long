NAME = so_long
LIBFT = ./libft/libft.a
LIBMLX	= ./MLX42

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address 
HEADERS	:= -I $(LIBMLX)/include/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

BOLD = \033[1m
GREEN= \033[32m
COLOR_RESET = \033[0m

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC = main.c \
\
src/free/finish_game.c \
src/free/free_map.c \
src/free/free_arr_pos_col.c \
\
src/main_functions/get_initial_parameters.c \
src/main_functions/map_is_ok.c \
src/main_functions/n_arguments_ok.c \
src/main_functions/create_window.c \
src/main_functions/draw_map.c \
src/main_functions/load_img.c \
\
src/map_is_ok/is_map_null.c \
src/map_is_ok/no_strange_obj.c \
src/map_is_ok/ok_number_c_e_p.c \
src/map_is_ok/is_rectangular.c \
src/map_is_ok/wall_is_ok.c \
src/map_is_ok/get_2_dimensions_map.c \
src/map_is_ok/max_x_y_ok.c \
src/map_is_ok/no_empty_lines.c \
src/map_is_ok/flood_fill_ok.c \
src/map_is_ok/name_is_ok.c \
src/map_is_ok/get_one_line_map.c \
src/map_is_ok/ft_open.c \
\
src/keyhook/keyhook.c \
src/keyhook/move_hero.c \
src/keyhook/try_to_move.c \
src/keyhook/subs_n_collectables.c \
\
src/unclasified/get_map.c \
src/unclasified/get_n_lines.c \
src/unclasified/y_max_arr.c \
src/unclasified/get_obj_pos.c \
src/unclasified/print_map.c

all: $(NAME)
$(NAME):  $(OBJ) $(LIBFT) libmlx
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME) $(HEADERS) 
	@echo "$(GREEN)$(BOLD) So_long program created!$(COLOR_RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(LIBFT):
	@$(MAKE) -C ./libft

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@rm -f $(OBJ) $(NAME)
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(LIBFT)
	@$(MAKE) -C libft fclean

re: fclean all

g3:
	@gcc $(SRC) libft/*.c -g3 -Imlx -o so_long

.PHONY: all clean fclean re g3
