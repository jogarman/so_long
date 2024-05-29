/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flood.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:32:04 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/29 22:01:24 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* write c char in coordenates x & y*/
int	put_in_pos(char **map, char c, int x, int y)
{	
	int		x_max;
	int		y_max;
	//char	**map_2;
	
	x_max = ft_strlen(map[0]);
	//map_2 = map;
	y_max = 0;
	while (map[y_max] != NULL)
	{
		y_max++;
	}
	printf("x_max-%d-//y_max-%d\n", x_max, y_max);
	if (map[y][x] != '1')
	{
		map[y][x] = c;
		return (0);
	}
	else
		return (-1);
	/* poner limines de map y verificar que x e y son inferiores*/	
	
	ft_putstr_fd("put_in_pos failed", 2);
	exit(-1);
}

int	fill_flood(char **map)
{
	
	printf("---X: %d---\n", get_obj_pos(map, 'P', 'x'));
	printf("---Y: %d---\n", get_obj_pos(map, 'P', 'y'));
	printf("--%d--\n", put_in_pos(map, 'w', '1', '1'));
	printf("--%s--", map[1]);
	return 0;
}
