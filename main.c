/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/10 19:01:23 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
void keyhook(mlx_key_data_t keydata, void* param)
{
	mlx_image_t* img_hero = param;
	//printf("%i", img_hero->height);
	// borrar puts
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		puts("a ");
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		puts("w");
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		img_hero->instances[0].enabled = false;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		puts("d");
}
int32_t	main(int n, char *argv[])
{
	mlx_t*		mlx;
	s_img 		img;
	
	n_arguments_ok(n);
	map_is_ok(argv);
	mlx = create_window(argv[1]);
	img = load_img(mlx);
	// hasta aqui bien

	
	if (!img.floor)
        error();
	if (mlx_image_to_window(mlx, img.floor, 0, 0) < 0)
		error();
	if (mlx_image_to_window(mlx, img.hero, 0, 0) < 0)
        error();


	mlx_key_hook(mlx, &keyhook, img.hero);
	mlx_loop(mlx);
	
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img.floor);
	//mlx_delete_texture(texture_floor); eliminar todas las texturas
	mlx_terminate(mlx);
	mlx_loop(mlx);
	//mlx_delete_image(mlx, img_floor);
	//mlx_delete_texture(texture_tile);
	//mlx_terminate(mlx);*/
	//return (EXIT_SUCCESS);
}