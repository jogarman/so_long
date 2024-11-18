/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:48:58 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 12:25:17 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->images.hero);
	mlx_delete_image(game->mlx, game->images.collectable);
	mlx_delete_image(game->mlx, game->images.exit);
	mlx_delete_image(game->mlx, game->images.wall);
	mlx_delete_image(game->mlx, game->images.floor);
}

void	finish_game(t_game *game, int success)
{
	if (success == 1)
		ft_putstr_fd("\033[32mCongrats! you won the game!\033[0m\n", 1);
	free_map(game->map);
	free_arr_pos_col(game->arr_pos_col);
	free_images(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
