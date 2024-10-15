/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/15 14:59:30 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	mv_up(t_game game)
{
	int	pos_p[2];
	char	obj;
	
	pos_p[0] = get_obj_pos(game.map, 'P', 'x');
	pos_p[1] = get_obj_pos(game.map, 'P', 'y');
	printf("pos_p: %d ,%d\n", pos_p[0], pos_p[1]);
	obj = 'P';
	pos_p[1] --;
	draw_new_img(game, pos_p, obj);
	draw_new_img(game, pos_p, obj);

	return (1);
}


void keyhook(mlx_key_data_t keydata, void *params)
{
	int		pos_p[1];
	t_game	*game;
	
	game = params;
	//pos_p[0] = get_obj_pos(((s_game*)game)->map, 'P', 'x');
	//pos_p[1] = get_obj_pos(((s_game*)game)->map, 'P', 'y');

	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
	{
		mv_up(*game);
		puts("a");
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
	{
		mv_up(*game);
		puts("w");
	}	
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		puts("s");
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		puts("d");
	if ((keydata.key == MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx); // da seg fault
}


/* continuar  con mover el hero.
falta:
- ocultar la salida
- concretar cuando visualizar la salida
- poner el contador de movimientos
- mover el hero
- restringir movimiento del hero
*/
int32_t	main(int n, char *argv[])
{
	t_img 		img;
	t_game		game;
	
	n_arguments_ok(n);
	//printf("main\n");
	game.map = map_is_ok(argv, game);
	get_initial_parameters(&game);
	game.mlx = create_window(argv[1], game.map);
	game.images = load_img(game.mlx);
	draw_map(game.images, game.map, game.mlx);

	mlx_key_hook(game.mlx, &keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}