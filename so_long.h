/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:54:21 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 00:22:32 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct parse_err
{
	char	*row_err;
}	parse_err;

/*********pos ? *********/
int	get_obj_pos(char **map, char object, char c);
/******** src ***********/
char	**get_map(char *argv[]);
char	*get_one_line_map(char *argv[], int fd);

int		get_n_rows(char *map);
int		is_map_null(char *map);
void	n_arguments_ok(int argc);
int		ft_open(char *argv);

int		fill_flood(char **map);
void	free_map(char **map, int size);

/*******  map_is_ok  ********/
int		map_is_ok(char *argv[]);
int		no_strange_obj(char	*map);
int		is_map_null(char *map);
int		ok_number_c_e_p(char *map);
int		is_rectangular(char *argv[]);
int		wall_ok(char *argv[]);
int		no_empty_lines(char *one_line_map);
int		fill_flood(char *map[]);
int		name_is_ok(char *prog_name);