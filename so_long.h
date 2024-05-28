/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:54:21 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/28 23:57:55 by jgarcia3         ###   ########.fr       */
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



/******** src ***********/
char	**get_map(char *argv[]);
char	*get_one_line_map(char *argv[]);

int		get_n_rows(char *map);
int		is_map_null(char *map);
void	n_arguments_ok(int argc);
int		ft_open(char *argv);

/*******  map_is_ok  ********/
int		map_is_ok(char *argv[]);
int		no_strange_obj(char	*map);
int		is_map_null(char *map);
int		ok_number_c_e_p(char *map);
int		is_rectangular(char *argv[], char **map);
int		wall_ok(char *argv[]);

