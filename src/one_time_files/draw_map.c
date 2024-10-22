/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:51:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/22 14:07:02 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdio.h>

void	draw_map(t_img img, char **map, mlx_t* mlx)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_image_to_window(mlx, img.wall, x * CAVAS_SIZE, y * CAVAS_SIZE);
			if (map[y][x] == '0')
				mlx_image_to_window(mlx, img.floor, x * CAVAS_SIZE, y * CAVAS_SIZE);
			if (map[y][x] == 'C')
				mlx_image_to_window(mlx, img.collectable, x * CAVAS_SIZE, y * CAVAS_SIZE);
			if (map[y][x] == 'E')
				mlx_image_to_window(mlx, img.exit, x * CAVAS_SIZE, y * CAVAS_SIZE);
			if (map[y][x] == 'P')
				mlx_image_to_window(mlx, img.hero, x * CAVAS_SIZE, y * CAVAS_SIZE);
			x++;
		}
		y++;
	}
}
