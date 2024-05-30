/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:28:15 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 17:25:55 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	err_exit(char *error, char *one_line_map)
{
	ft_putstr_fd(error, 2);
	free(one_line_map);
	exit(-1);
}

int	map_is_ok(char *argv[])
{
	char	*one_line_map;

	one_line_map = get_one_line_map(argv, 3);
	if (name_is_ok(argv[1]))
		err_exit("Error:\n-Map extension must be .ber", one_line_map);
	if (is_map_null(one_line_map))
		err_exit("Error:\n-Map is Null", one_line_map);
	if (no_empty_lines(one_line_map))
		err_exit("Error:\n-Map has empty lines", one_line_map);
	if (no_strange_obj(one_line_map))
		err_exit("Error:\n-There are strange objects in map", one_line_map);
	if (ok_number_c_e_p(one_line_map))
		err_exit("Error:\n-Wrong number of objects", one_line_map);
	if (is_rectangular(argv))
		err_exit("Error:\n-Map is not rectangular", one_line_map);
	if (wall_ok(argv))
		err_exit("Error:\n-Map wall is not ok", one_line_map);
	if (flood_fill_ok(argv))
		err_exit("Error:\n-Map doesn't have a solution", one_line_map);
	return (free(one_line_map), 0);
}
