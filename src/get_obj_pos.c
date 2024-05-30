/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:37:29 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 14:09:49 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* imputs:
	-map
	-object. 'P' or 'E' 
	-'x' or 'y' you want to return
returns:
	- x or y of object
	- if doesn´t find it*/
int get_obj_pos(char **map, char obj, char c)
{
	int		y;
	int 	x;
	char	**map_dup;

	map_dup = map;
	y = 0;
	x = 0;
	while (map_dup[y] != NULL && (c == 'y' || c == 'x') && (obj == 'P' || obj == 'E'))
	{
		while (map_dup[y][x] != '\0')
		{
			if (map_dup[y][x] == obj && c == 'y')
				return (map_dup - map);
			if (map_dup[y][x] == obj && c == 'x')
				return (x);
			x++;
		}
		x = 0;
		map_dup++;
	}
	ft_putstr_fd("get_p_y failed", 2);
	exit(-1);
}
