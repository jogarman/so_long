/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:51:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/10 22:47:19 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdio.h>

void	draw_map(s_img img, char **map, mlx_t* mlx)
{
	int		x;
	int		y;
	int		tile_size;
	
	x = 0;
	y = 0;
	tile_size = 64;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_image_to_window(mlx, img.wall, x * tile_size, y * tile_size);
			if (map[y][x] == '0')
				mlx_image_to_window(mlx, img.floor, x * tile_size, y * tile_size);
			if (map[y][x] == 'C')
				mlx_image_to_window(mlx, img.collectable, x * tile_size, y * tile_size);
			if (map[y][x] == 'E')
				mlx_image_to_window(mlx, img.exit, x * tile_size, y * tile_size);
			if (map[y][x] == 'P')
				mlx_image_to_window(mlx, img.hero, x * tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}
