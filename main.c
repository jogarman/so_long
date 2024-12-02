/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/12/02 14:35:01 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//search "alloc" y ver si están protegido
int	main(int argc, char *argv[])
{
	t_game		game;

	n_arguments_ok(argc);
	map_is_ok(argv, &game);
	get_initial_parameters(&game);
	game.mlx = create_window(argv[1], game.map);
	game.images = load_img(game.mlx, &game);
	draw_map(game);
	mlx_key_hook(game.mlx, &keyhook, &game);
	mlx_loop(game.mlx);
	finish_game(&game, 0);
}
