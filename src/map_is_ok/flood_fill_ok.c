/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_ok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:32:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 17:23:09 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_xy_within_limits(char **map, int x, int y)
{
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
	if (check_xy_within_limits(map, x, y) == 0)
	{ 
		if (map[y][x] != '1' && map[y][x] != c)
		{
			map[y][x] = c;
			return (0);
		}
		else
			return (-1);
	}
	ft_putstr_fd("put_in_pos in fill_flood failed", 2);
	free_map(map);
	exit(-1);
}

int	flood_fill_recurs(char **map, int x, int y)
{
	if (put_in_pos(map, 'w', x, y) != -1)
	{
		flood_fill_recurs(map, x + 1, y);
		flood_fill_recurs(map, x - 1, y);
		flood_fill_recurs(map, x, y + 1);
		flood_fill_recurs(map, x, y - 1);
	}
	return 0;
}

int	how_many_obj_in_map(char **map, char obj)
{
	int	i;
	int	j;
	int counter;

	i = 0;
	j = 0;
	counter = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == obj)
				counter++;
			j++;
		}
		j = 0;
		i++;
	}
	return (counter);
}

int	flood_fill_ok(char **argv)
{
	int		x;
	int		y;
	int		n_exits;
	int		n_collectables;
	char	**map;

	map = get_map(argv);
	x = get_obj_pos(map, 'P', 'x');
	y = get_obj_pos(map, 'P', 'y');
	flood_fill_recurs(map, x, y);
	n_exits = how_many_obj_in_map(map, 'E');
	n_collectables = how_many_obj_in_map(map, 'C');
	if (n_exits == 0 && n_collectables == 0)
	{
		free_map(map);
		return (0);
	}
	else
	{
		free_map(map);
		return(-1);
	}
}
