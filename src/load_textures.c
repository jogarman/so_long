/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:58:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/08 17:18:19 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

s_textures	load_textures()
{
	s_textures	textures;

	textures.hero = mlx_load_png("./textures/me.png");
	textures.collectable = mlx_load_png("./textures/money.png");
	textures.exit = mlx_load_png("./textures/plane.png");
	textures.wall = mlx_load_png("./textures/wall.png");
	textures.floor = mlx_load_png("./textures/floor.png");

	return (textures);
}