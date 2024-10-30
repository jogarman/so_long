/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs_n_collectables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:13:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/30 21:37:40 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	enabling_exit(t_game *game)
{
	int		exit_pos[2];
	t_list *list = NULL;

	game->images.exit->enabled = 1;
	exit_pos[0] = get_obj_pos(game->map, 'E', 'x');
	exit_pos[1] = get_obj_pos(game->map, 'E', 'y');
	mlx_image_to_window(game->mlx, game->images.exit, 
		exit_pos[0] * CAVAS_SIZE, exit_pos[1] * CAVAS_SIZE);
}

/* is position in array? 
n_col_ini: lenght of array*/
int		pos_is_in_arr(t_collect_pos	*arr_pos_col, int x, int y, int n_col_ini)
{
	int	n;

	n = 0;
	while(n != n_col_ini)
	{
		if (arr_pos_col[n].pos_col[0] == x)
			if (arr_pos_col[n].pos_col[1] == y)
			{
				return (1);
			}
		n++;
	}
	return (0);
}

/*add position to array
n_col_ini: lenght of array*/
void	add_pos_to_arr(t_collect_pos *arr_pos_col, int x, int y, int n_col_ini)
{
	int	n;
	
   if (n_col_ini <= 0)
        return;
	n = 0;
	while(arr_pos_col[n].pos_col[0] != -1)
	{
		if (n == n_col_ini - 1)
			return ;
		n++;
	}
	arr_pos_col[n].pos_col[0] = x;
	arr_pos_col[n].pos_col[1] = y;
}

/*
Substract n_collectables if hero never have been there
Enable exit if n_collectables = 0
*/
void	subs_n_collectables(t_game *game, int x, int y)
{
	if (!pos_is_in_arr(game->arr_pos_col, x, y, game->n_collectables_ini))
	{
		game->n_collectables--;
		add_pos_to_arr(game->arr_pos_col, x, y, game->n_collectables_ini);
	}
	if (game->n_collectables == 0)
		game->exit_enable = 1;
	if (game->n_collectables == 0)
		enabling_exit(game);
}