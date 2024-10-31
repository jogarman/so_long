NAME = so_long
LIBFT = ./libft/libft.a
LIBMLX	= ./MLX42

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -g3 -Wall -Wextra -Werror #-fsanitize=address 
HEADERS	:= -I ./include -I $(LIBMLX)/include/MLX42   # el primer include es redundante
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

BOLD = \033[1m
GREEN= \033[32m
COLOR_RESET = \033[0m

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC = main.c \
\
src/map_is_ok/is_map_null.c src/map_is_ok/map_is_ok.c src/map_is_ok/no_strange_obj.c \
src/map_is_ok/ok_number_c_e_p.c src/map_is_ok/is_rectangular.c src/map_is_ok/wall_is_ok.c \
src/map_is_ok/get_2_dimensions_map.c src/map_is_ok/max_x_y_ok.c \
\
src/keyhook/keyhook.c src/keyhook/move_hero.c src/keyhook/try_to_move.c \
src/keyhook/subs_n_collectables.c \
\
src/map_is_ok/no_empty_lines.c src/map_is_ok/flood_fill_ok.c src/map_is_ok/name_is_ok.c \
\
src/one_time_files/load_img.c src/one_time_files/create_window.c src/one_time_files/draw_map.c \
src/one_time_files/get_initial_parameters.c\
\
src/one_time_files/get_n_lines.c src/one_time_files/get_one_line_map.c \
src/one_time_files/n_arguments_ok.c src/one_time_files/y_max_arr.c \
\
src/ft_open.c src/get_map.c src/get_obj_pos.c src/free_map.c \
\
src/end_program.c src/obj_in_pos.c\
\
src/print_map.c src/print_arr_pos_col.c

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
