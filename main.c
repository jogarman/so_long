/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/08 17:13:38 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

#define WIDTH 512
#define HEIGHT 2880

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
void keyhook(mlx_key_data_t keydata, void* param)
{
	mlx_image_t* img_me = param;
	//printf("%i", img_me->height);
	// borrar puts
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		puts("a ");
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		puts("w");
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		img_me->instances[0].enabled = false;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		puts("d");
}

int32_t	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
        error();
	load_textures();
	/*
	mlx_texture_t* texture_me = mlx_load_png("./textures/me.png");
	mlx_texture_t* texture_tile = mlx_load_png("./textures/tile.png");
	if (!texture_tile)
        error();
		
	mlx_image_t* img_tile = mlx_texture_to_image(mlx, texture_tile);
	mlx_image_t* img_me = mlx_texture_to_image(mlx, texture_me);
	if (!img_tile)
        error();

	if (mlx_image_to_window(mlx, img_tile, 0, 0) < 0)
		error();
	if (mlx_image_to_window(mlx, img_me, 0, 0) < 0)
        error();
	
	mlx_key_hook(mlx, &keyhook, img_me);
	mlx_loop(mlx);
	
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img_tile);
	mlx_delete_texture(texture_tile);
	mlx_terminate(mlx);*/
	mlx_loop(mlx);
	//mlx_delete_image(mlx, img_tile);
	//mlx_delete_texture(texture_tile);
	//mlx_terminate(mlx);*/
	return (EXIT_SUCCESS);
}