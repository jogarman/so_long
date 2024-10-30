/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_parameters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:22:16 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/30 20:49:24 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		get_n_collectables(char **map)
{
	int		y;
	int 	x;
	int		n_collectables;

	y = 0;
	x = 0;
	n_collectables = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{

			if (map[y][x] == 'C')
				n_collectables++;
			x++;
		}
		x = 0;
		y++;
	}
	return (n_collectables);
}

void	create_arr_collectables(t_game *game)
{
	int	n;
	int	arr[2];

	game->n_collectables_ini = game->n_collectables;
	game->arr_pos_col = malloc((game->n_collectables) * sizeof(t_collect_pos));
	if (game->arr_pos_col == NULL)
		exit(1);
	n = 0;
	while (n < game->n_collectables_ini)
	{
		game->arr_pos_col[n].pos_col[0] = -1;
		game->arr_pos_col[n].pos_col[1] = -1;
		n++;
	}
}

void	get_initial_parameters(t_game *game)
{
	game->p_pos[0] = get_obj_pos(game->map, 'P', 'x');
	game->p_pos[1] = get_obj_pos(game->map, 'P', 'y');
	game->n_collectables = get_n_collectables(game->map);
	game->n_moves = 0;
	if (game->n_collectables == 0)
		game->exit_enable = 1;
	else
	{
		game->exit_enable = 0;
		create_arr_collectables(game);
	}
}
