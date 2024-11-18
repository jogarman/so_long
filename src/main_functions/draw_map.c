/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:51:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 13:33:58 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdio.h>

void	draw_canvas(mlx_t *mlx, t_img img, int xy[2], char tile)
{
	if (tile == '1')
		mlx_image_to_window(mlx, img.wall, xy[0] * SIZE, xy[1] * SIZE);
	if (tile == '0')
		mlx_image_to_window(mlx, img.floor, xy[0] * SIZE, xy[1] * SIZE);
	if (tile == 'C')
	{
		mlx_image_to_window(mlx, img.floor, xy[0] * SIZE, xy[1] * SIZE);
		mlx_image_to_window(mlx, img.collectable, xy[0] * SIZE, xy[1] * SIZE);
	}
	if (tile == 'E')
	{
		mlx_image_to_window(mlx, img.floor, xy[0] * SIZE, xy[1] * SIZE);
		mlx_image_to_window(mlx, img.exit, xy[0] * SIZE, xy[1] * SIZE);
		img.exit->enabled = 0;
	}
	if (tile == 'P')
	{
		mlx_image_to_window(mlx, img.floor, xy[0] * SIZE, xy[1] * SIZE);
		mlx_image_to_window(mlx, img.hero, xy[0] * SIZE, xy[1] * SIZE);
	}
}

void	draw_map(t_img img, char **map, mlx_t *mlx)
{
	int		xy[2];
	char	tile;

	xy[1] = 0;
	while (map[xy[1]])
	{
		xy[0] = 0;
		while (map[xy[1]][xy[0]])
		{
			tile = map[xy[1]][xy[0]];
			draw_canvas(mlx, img, xy, tile);
			xy[0]++;
		}
		xy[1]++;
	}
}

/*
void	draw_map(t_img img, char **map, mlx_t *mlx)
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
				mlx_image_to_window(mlx, img.wall, x * SIZE, y * SIZE);
			if (map[y][x] == '0')
				mlx_image_to_window(mlx, img.floor, x * SIZE, y * SIZE);
			if (map[y][x] == 'C')
			{
				mlx_image_to_window(mlx, img.floor, x * SIZE, y * SIZE);
				mlx_image_to_window(mlx, img.collectable, x * SIZE, y * SIZE);
			}
			if (map[y][x] == 'E')
			{
				mlx_image_to_window(mlx, img.floor, x * SIZE, y * SIZE);
				mlx_image_to_window(mlx, img.exit, x * SIZE, y * SIZE);
				img.exit->enabled = 0;
			}
			if (map[y][x] == 'P')
			{
				mlx_image_to_window(mlx, img.floor, x * SIZE, y * SIZE);
				mlx_image_to_window(mlx, img.hero, x * SIZE, y * SIZE);
			}
			x++;
		}
		y++;
	}
}
*/