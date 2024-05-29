/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flood.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:32:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 01:29:36 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_xy_within_limits(char **map, int x, int y)
{
	printf("x: %d\ny: %d\n", x, y);
	printf("x_max: %zu\ny_max_arr: %d\n", ft_strlen(map[0]),  y_max_arr((const char **)map));
	
	if (y >= y_max_arr((const char **)map))
	{
		ft_putstr_fd("check_y_in_limits failed", 2);
		exit (-1);
	}
	if ((size_t)x >= ft_strlen(map[0]))
	{
		ft_putstr_fd("check_x_in_limits failed", 2);
		exit (-1);
	}
	return (0);
}

/* write c char in coordenates x & y*/
int	put_in_pos(char **map, char c, int x, int y)
{	
	check_xy_within_limits(map, x, y);
	if (map[y][x] != '1')
	{
		map[y][x] = c;
		return (0);
	}
	else
		return (-1);
	ft_putstr_fd("put_in_pos failed", 2);
	exit(-1);
}

int	fill_flood(char **map)
{
	//printf("---X: %d---\n", get_obj_pos(map, 'P', 'x'));
	//printf("---Y: %d---\n", get_obj_pos(map, 'P', 'y'));
	put_in_pos(map, 'W', 1, 1);
	put_in_pos(map, 'W', 1, 40);
	print_map(map);
	return 0;
}
