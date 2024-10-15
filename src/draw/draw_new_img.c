/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:52:15 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/15 13:15:37 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* Draw a new movement */

void	draw_new_img(t_game g, int xy[2], char obj)
{
	int x;
	int y;

	x = xy[0];
	y = xy[1];
	mlx_image_to_window(g.mlx, g.images.hero, x * CAVAS_SIZE, y * CAVAS_SIZE);
}