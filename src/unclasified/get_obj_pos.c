/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:37:29 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 14:42:36 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* imputs:
	-map
	-object. 'P' or 'E' 
	-'x' or 'y' you want to return
returns:
	- x or y of object
	- if doesn´t find it 

Original loop-> while (map_dup[y] != NULL
&& (xy == 'y' || xy == 'x') && (obj == 'P' || obj == 'E'))
*/
int	get_obj_pos(char **map, char obj, char xy)
{
	int		y;
	int		x;
	char	**map_dup;

	map_dup = map;
	y = 0;
	x = 0;
	while (map_dup[y] != NULL && (obj == 'P' || obj == 'E'))
	{
		while (map_dup[y][x] != '\0')
		{
			if (map_dup[y][x] == obj && xy == 'y')
				return (map_dup - map);
			if (map_dup[y][x] == obj && xy == 'x')
				return (x);
			x++;
		}
		x = 0;
		map_dup++;
	}
	if (map_dup[y] == NULL)
		ft_putstr_fd("get_obj_pos -> map_dup[y] == NULL", 2);
	if (!((xy == 'y' || xy == 'x') && (obj == 'P' || obj == 'E')))
		ft_putstr_fd("get_obj_pos -> xy or P, E", 2);
	exit(-1);
}
