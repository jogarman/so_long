/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:58:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/10 19:00:05 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
//	printf("\nhola\n");

s_img	load_img(mlx_t* mlx)
{
	s_textures	textures;
	s_img 		img;
	
	textures.hero = mlx_load_png("./textures/me.png");
	textures.collectable = mlx_load_png("./textures/money.png");
	textures.exit = mlx_load_png("./textures/plane.png");
	textures.wall = mlx_load_png("./textures/wall.png");
	textures.floor = mlx_load_png("./textures/floor.png");
	
	img.floor = mlx_texture_to_image(mlx, textures.floor);
	img.hero = mlx_texture_to_image(mlx, textures.hero);
	img.collectable = mlx_texture_to_image(mlx, textures.collectable);
	img.exit = mlx_texture_to_image(mlx, textures.exit);
	img.wall = mlx_texture_to_image(mlx, textures.wall);
		
	mlx_delete_texture(textures.hero);
	mlx_delete_texture(textures.collectable);
	mlx_delete_texture(textures.exit);
	mlx_delete_texture(textures.wall);
	mlx_delete_texture(textures.floor);

	return (img);
}