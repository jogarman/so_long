/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:51:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/12/02 14:34:51 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdio.h>

void	finish_with_fail(t_game *game, char e)
{
	ft_putstr_fd("fail on img_to_window", 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd(e, 2);
	finish_game(game, 0);
}

void	img_to_window(t_game g, char object, int x, int y)
{
	if (object == 'w')
	{
		if (mlx_image_to_window(g.mlx, g.images.wall, x, y) == -1)
			finish_with_fail(g.mlx, object);
	}
	else if (object == 'f')
	{
		if (mlx_image_to_window(g.mlx, g.images.floor, x, y) == -1)
			finish_with_fail(g.mlx, object);
	}
	else if (object == 'c')
	{
		if (mlx_image_to_window(g.mlx, g.images.collectable, x, y) == -1)
			finish_with_fail(g.mlx, object);
	}
	else if (object == 'e')
	{
		if (mlx_image_to_window(g.mlx, g.images.exit, x, y) == -1)
			finish_with_fail(g.mlx, object);
	}
	else if (object == 'h')
	{
		if (mlx_image_to_window(g.mlx, g.images.hero, x, y) == -1)
			finish_with_fail(g.mlx, object);
	}
}

void	draw_canvas(t_game g)
{
	int	x;
	int	y;

	x = g.xy[0] * SIZE;
	y = g.xy[1] * SIZE;
	if (g.tile == '1')
		img_to_window(g, 'w', x, y);
	if (g.tile == '0')
		img_to_window(g, 'f', x, y);
	if (g.tile == 'C')
	{
		img_to_window(g, 'f', x, y);
		img_to_window(g, 'c', x, y);
	}
	if (g.tile == 'E')
	{
		img_to_window(g, 'f', x, y);
		img_to_window(g, 'e', x, y);
		g.images.exit->enabled = 0;
	}
	if (g.tile == 'P')
	{
		img_to_window(g, 'f', x, y);
		img_to_window(g, 'h', x, y);
	}
}

void	draw_map(t_game game)
{
	game.xy[1] = 0;
	while (game.map[game.xy[1]])
	{
		game.xy[0] = 0;
		while (game.map[game.xy[1]][game.xy[0]])
		{
			game.tile = game.map[game.xy[1]][game.xy[0]];
			draw_canvas(game);
			game.xy[0]++;
		}
		game.xy[1]++;
	}
}
