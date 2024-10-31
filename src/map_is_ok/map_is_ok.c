/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:28:15 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/31 17:38:44 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// /* POR HACER PENDIENTE*/
// void free_game(t_game *game)
// {
// 	ft_putstr_fd(2, "free_game\n");
	
// }

void	err_exit_free_game(char *error, char **map)
{
	ft_putstr_fd(error, 2);
	free_map(map);
	exit(-1);
}

void	err_exit_olm(char *error, char *one_line_map)
{
	ft_putstr_fd(error, 2);
	free(one_line_map);
	exit(-1);
}

char	**map_is_ok(char *argv[], t_game *game)
{
	char	*one_line_map;

	one_line_map = get_one_line_map(argv, 3);
	if (name_is_ok(argv[1]))
		err_exit_olm("Error:\n-Map extension must be .ber", one_line_map);
	if (is_map_null(one_line_map))
		err_exit_olm("Error:\n-Map is Null", one_line_map);
	if (no_empty_lines(one_line_map))
		err_exit_olm("Error:\n-Map has empty lines", one_line_map);
	if (no_strange_obj(one_line_map))
		err_exit_olm("Error:\n-There are strange objects in map", one_line_map);
	if (ok_number_c_e_p(one_line_map))
		err_exit_olm("Error:\n-Wrong number of objects", one_line_map);
	if (is_rectangular(argv))
		err_exit_olm("Error:\n-Map is not rectangular", one_line_map);
	if (wall_ok(argv))
		err_exit_olm("Error:\n-Map wall is not ok", one_line_map);
	free(one_line_map);
	game->map = get_map(argv);
	if (max_x_y_ok(game->map))
		err_exit_free_game("Error:\n-Map so big", game->map);
	free_map(game->map);
	game->map = get_map(argv);
	if (flood_fill_ok(game->map))
		err_exit_free_game("Error:\n-Map doesn't have a solution", game->map);
	game->map = get_map(argv);
	return 0;
}
