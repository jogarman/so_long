/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/16 16:22:04 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

/* x and y are the position to where yo are moving the hero */
void	move_hero(t_game g, int x, int y, char obj_next_pos)
{
	if (obj_next_pos == '0' || obj_next_pos == 'P' || obj_next_pos == 'C')
	{
		mlx_image_to_window(g.mlx, g.images.hero, x * CAVAS_SIZE, y * CAVAS_SIZE);
		//mlx_image_to_window(g.mlx, g.images.floor, g.p_pos[0] * CAVAS_SIZE, g.p_pos[1] * CAVAS_SIZE);

		write(1, "\np_pos", 6);
		ft_putnbr_fd(g.p_pos[0], 1);
		ft_putnbr_fd(g.p_pos[1], 1);
		write(1, "\nxy_final", 9);
		ft_putnbr_fd(x, 1);
		ft_putnbr_fd(y, 1);
		
		g.p_pos[0] = x;
		g.p_pos[1] = y;
		
		ft_putnbr_fd(g.n_moves, 1);
		write(1, "\nnuevo p_pos", 11);
		ft_putnbr_fd(g.p_pos[0], 1);
		ft_putnbr_fd(g.p_pos[1], 1);
		
		g.n_moves ++;
		//printf("p_pos x %d\np_pos y %d\n", x, y);

	}
}


/*
move_hero funtion:
inputs 
-pos_ini, 
-pos_fin 

- ir a 0 ó Exit[no_enable] o P **mover**
- ir a c					   **mover**
- Salir
- No ir a pared
*/
int	try_to_mv(t_game game, char direction)
{
	int		desired_next_xy[2];
	char	obj_next_pos;

	if (direction == 'a')
	{
		desired_next_xy[0] = game.p_pos[0] - 1;
		desired_next_xy[1] = game.p_pos[1];
	}
	if (direction == 'w')
	{
		desired_next_xy[0] = game.p_pos[0];
		desired_next_xy[1] = game.p_pos[1] - 1;
	}
	if (direction == 's')
	{
		desired_next_xy[0] = game.p_pos[0];
		desired_next_xy[1] = game.p_pos[1] + 1;
	}
	if (direction == 'd')
	{
		desired_next_xy[0] = game.p_pos[0] + 1;
		desired_next_xy[1] = game.p_pos[1];
	}
	obj_next_pos = obj_in_pos(game, desired_next_xy[0], desired_next_xy[1]);
	move_hero(game, desired_next_xy[0], desired_next_xy[1], obj_next_pos);
	return (1);
}


void keyhook(mlx_key_data_t keydata, void *params)
{
	int		pos_p[1];
	t_game	*game;
	
	game = params;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
	{
		try_to_mv(*game, 'a');
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
	{
		try_to_mv(*game, 'w');
	}	
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
	{
		try_to_mv(*game, 's');
	}
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
	{
		try_to_mv(*game, 'd');
	}
	if ((keydata.key == MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}


/* continuar con mover el hero.
falta:
coreegir bug para que p_pos cambie
esto en el main no corre en el loop
	write(1, '\n', 1);
	ft_putnbr_fd(game.p_pos[0], 1);
	ft_putnbr_fd(game.p_pos[1], 1);
	write(1, '\n', 1);
	
- ocultar la salida
- concretar cuando visualizar la salida
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
