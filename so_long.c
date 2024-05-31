/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:52:32 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/31 11:21:34 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
/* 
map_ok perfecto!
*/
int		main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	

	n_arguments_ok(argc);
	map_is_ok(argv);
	
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	(void)mlx_win;
	//start_game();
}