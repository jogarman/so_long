NAME = so_long
LIBFT = ./libft/libft.a

CC = gcc
ARFLAGS = -rcs
AR = ar
CFLAGS = -Wall -Wextra -Werror

GREEN= \033[32m
COLOR_RESET = \033[0m

OBJ = $(SRC:.c=.o)

SRC = so_long.c get_utils.c n_arguments_ok.c map_is_ok.c ft_open.c
#OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
$(NAME): $(LIBFT) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) so_long program created!$(COLOR_RESET)"

#bonus: $(BONUS)
#$(BONUS): $(LIBFT) $(LIBFT) $(OBJ_BONUS)
#	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS)
#	@echo "$(GREEN) so_long program created!$(COLOR_RESET)"

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	@rm -f $(OBJ) $(OBJ_BONUS) $(NAME) $(BONUS)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(LIBFT)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
