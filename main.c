/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/30 21:39:50 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

/*
corregir errores al hacer make.
finalizar el juego cuando alcanzo salida
quitar leaks y problemas varios
*/
int32_t	main(int argc, char *argv[])
{
	t_img 		img;
	t_game		game;
	
	n_arguments_ok(argc);
	map_is_ok(argv, &game);
	get_initial_parameters(&game);

	game.mlx = create_window(argv[1], game.map);

	game.images = load_img(game.mlx);
	draw_map(game.images, game.map, game.mlx);

	mlx_key_hook(game.mlx, &keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
