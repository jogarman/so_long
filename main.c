/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/10 23:03:26 by jgarcia3         ###   ########.fr       */
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


//create_window corregir problema con mapas en el limite
int32_t	main(int n, char *argv[])
{
	mlx_t*		mlx;
	s_img 		img;
	char**		map;
	
	n_arguments_ok(n);
	map = map_is_ok(argv);
	printf("--eee--");
	mlx = create_window(argv[1], map);
	printf("--eee--");
	img = load_img(mlx);
	// hasta aqui bien
	draw_map(img, map, mlx);


	//mlx_key_hook(mlx, &keyhook, img.hero);
	mlx_loop(mlx);
	

	mlx_terminate(mlx);
	mlx_loop(mlx);

}