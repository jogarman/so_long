/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:37:29 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/11 15:58:37 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*for debugging */
void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		write(1, map[i], ft_strlen(map[i]));
		i++;
	}
	write(1, "\n", 1);
}

/* imputs:
	-map
	-object. 'P' or 'E' 
	-'x' or 'y' you want to return
returns:
	- x or y of object
	- if doesn´t find it*/
int get_obj_pos(char **map, char obj, char xy)
{
	int		y;
	int 	x;

	y = 0;
	x = 0;
	print_map(map);
	while (map[y] != NULL && (xy == 'y' || xy == 'x') && (obj == 'P' || obj == 'E'))
	{
		//printf("-----get_obj_pos----");
		while (map[y][x] != '\0')
		{
			if (map[y][x] == obj && xy == 'y')
				return (y);
			if (map[y][x] == obj && xy == 'x')
				return (x);
			//if (map[x][y] != NULL)
			//	printf("x: %d\ny: %d\n simbolo: %c\n", x, y, map[x][y]);
			x++;
		}
		x = 0;
		y++;
		printf("-----YYYYYYYY----");

	}
	if (map[y] == NULL)
		ft_putstr_fd("get_obj_pos -> map_dup[y] == NULL", 2);
	if (!((xy == 'y' || xy == 'x') && (obj == 'P' || obj == 'E')))
		ft_putstr_fd("get_obj_pos -> xy or P, E", 2);
	exit(-1);
}
