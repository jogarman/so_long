/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:05:16 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/31 16:25:04 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


void	free_arr_pos_col(t_collect_pos *arr_pos_col)
{
	if (arr_pos_col != NULL)
		free(arr_pos_col);
}


void	finish_game(t_game *game, int success)
{
	if (success == 1)
		ft_putstr_fd("\033[32mCongrats! you won the game!\033[0m\n", 1);
	free_map(game->map);
	free_arr_pos_col(game->arr_pos_col);
	mlx_terminate(game->mlx);	
	exit(EXIT_SUCCESS);
}

/* x and y are the position to where you are moving the hero */
void	move_hero(t_game *g, int x, int y, char obj_next_pos)
{
	if (obj_next_pos == '0' || obj_next_pos == 'P' || obj_next_pos == 'C'
		|| obj_next_pos == 'E')
	{
		mlx_image_to_window(
			g->mlx, g->images.floor,
			x * CAVAS_SIZE,
			y * CAVAS_SIZE);
		mlx_image_to_window(
			g->mlx, g->images.hero,
			x * CAVAS_SIZE,
			y * CAVAS_SIZE);
		mlx_image_to_window(
			g->mlx, g->images.floor,
			g->p_pos[0] * CAVAS_SIZE,
			g->p_pos[1] * CAVAS_SIZE);
		g->p_pos[0] = x;
		g->p_pos[1] = y;
		g->n_moves ++;
		ft_putnbr_fd(g->n_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	if (obj_next_pos == 'C')
		subs_n_collectables(g, x, y);
	if (obj_next_pos == 'E' && g->exit_enable == 1)
		finish_game(g, 1);
}
