/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:54:21 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/22 15:08:22 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "MLX42.h"

#define CAVAS_SIZE 64

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
	void	*hero;
	void	*collectable;
	void	*exit;
	void	*wall;
	void	*floor;
} t_img;

typedef struct s_game 
{
	mlx_t	*mlx;
	t_img	images;
	char	**map;
	int		p_pos[2];
	int		exit_enable;
	int		n_collectables;
	int		n_moves;
}	t_game;


/*****  one_time_files ******/
size_t	get_n_lines(char *argv[]);
int		y_max_arr(char **map);
char	*get_one_line_map(char *argv[], int fd);
void	n_arguments_ok(int argc);
void	get_initial_parameters(t_game *game);

/********  src ***********/
int		ft_open(char *argv);
char	**get_map(char *argv[]);
int		get_obj_pos(char **map, char object, char c);
void	free_map(char **map);
char	obj_in_pos(t_game *game, int x, int y);
/******** obj  ***********/
void	draw_new_img(t_game g, int xy[2], char obj);
/******** game ***********/
void	end_program(t_game game);


/*****  not_used   ********/
void	print_map(char **map); //se usa?
//int		get_n_rows(char *map);

/*****  map_is_ok  ********/
char	**map_is_ok(char *argv[], t_game game);
int		no_strange_obj(char	*map);
int		is_map_null(char *map);
int		ok_number_c_e_p(char *map);
int		is_rectangular(char *argv[]);
int		wall_ok(char *argv[]);
int		no_empty_lines(char *one_line_map);
int		flood_fill_ok(char *argv[], char **map);
int		name_is_ok(char *prog_name);
char	**get_2_dimensions_map(char *argv[]);
int		max_x_y_ok(char** map);

/*****  draw_map  ********/
void	draw_map(t_img img, char **map, mlx_t* mlx);
t_img	load_img(mlx_t* mlx);
mlx_t*	create_window(char* title, char** map);
