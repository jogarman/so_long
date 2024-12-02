/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:54:21 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/12/02 15:09:41 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "MLX42.h"

/* Cavas size*/
#define SIZE 64

typedef struct s_textures
{
	void	*hero;
	void	*collectable;
	void	*exit;
	void	*wall;
	void	*floor;
} t_textures;

typedef struct s_img
{
	void		*hero;
	void		*collectable;
	mlx_image_t	*exit;
	void		*wall;
	void		*floor;
} t_img;

typedef struct s_collect_pos
{
	int	pos_col[2];
}	t_collect_pos;

typedef struct s_game
{
	mlx_t			*mlx;
	t_img			images;
	char			**map;
	int				xy[2];
	char			tile;
	int				p_pos[2];
	int				exit_enable;
	int				n_collectables;
	int				n_collectables_ini;
	int				n_moves;
	t_collect_pos	*arr_pos_col;
}	t_game;


/*****  free_finish    ******/
void	finish_game(t_game *game, int success);
void	free_map(char **map);
void	free_arr_pos_col(t_collect_pos *arr_pos_col);

/******  keyhook        *********/
void	keyhook(mlx_key_data_t keydata, void *params);
void	move_hero(t_game *g, int x, int y, char obj_next_pos);
void	try_to_mv(t_game *game, char direction);
void	subs_n_collectables(t_game *game, int x, int y);

/******  main_functions *********/
mlx_t*	create_window(char* title, char** map);
void	draw_map(t_game *game);
t_img	load_img(mlx_t* mlx, t_game *game);
void	get_initial_parameters(t_game *game);
void	map_is_ok(char *argv[], t_game *game);
void	n_arguments_ok(int argc);

/*****  map_is_ok  **********/
int		no_strange_obj(char	*map);
int		is_map_null(char *map);
int		ok_number_c_e_p(char *map);
int		is_rectangular(char *argv[]);
int		wall_ok(char *argv[]);
int		no_empty_lines(char *one_line_map);
int		flood_fill_ok(char **map);
int		name_is_ok(char *prog_name);
char	**get_2_dimensions_map(char *argv[]);
int		max_x_y_ok(char** map);
char	*get_one_line_map(char *argv[], int fd);
int		ft_open(char *argv);

/********  unclasified ***********/
char	**get_map(char *argv[], int fd);
int		get_obj_pos(char **map, char object, char c);
void	print_map(char **map);
int		y_max_arr(char **map);
size_t	get_n_lines(char *argv[]);
