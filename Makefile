NAME = so_long
LIBFT = ./libft/libft.a

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror -g3

GREEN= \033[32m
COLOR_RESET = \033[0m

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC = so_long.c \
src/get_one_line_map.c src/n_arguments_ok.c src/ft_open.c src/get_map.c \
src/get_obj_pos.c \
src/map_is_ok/is_map_null.c src/map_is_ok/map_is_ok.c src/map_is_ok/no_strange_obj.c \
src/map_is_ok/ok_number_c_e_p.c src/map_is_ok/is_rectangular.c src/map_is_ok/wall_is_ok.c \
src/map_is_ok/no_empty_lines.c src/map_is_ok/flood_fill_ok.c src/map_is_ok/name_is_ok.c \
src/free_map.c src/y_max_arr.c src/print_map.c src/get_n_lines.c

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) so_long program created!$(COLOR_RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	@rm -f $(OBJ) $(NAME)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(LIBFT)
	$(MAKE) -C libft fclean

re: fclean all

g3:
	@gcc $(SRC) libft/*.c -g3 -fsanitize=address -o so_long

.PHONY: all clean fclean re g3
