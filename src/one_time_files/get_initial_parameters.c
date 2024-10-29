/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_parameters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:22:16 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/29 16:33:43 by jgarcia3         ###   ########.fr       */
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
	while (map[y] != '\0')
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

void	get_initial_parameters(t_game *game)
{
	game->p_pos[0] = get_obj_pos(game->map, 'P', 'x');
	game->p_pos[1] = get_obj_pos(game->map, 'P', 'y');
	game->n_collectables = get_n_collectables(game->map);
	game->n_moves = 0;
	if (game->n_collectables == 0)
		game->exit_enable = 1;
	else
		game->exit_enable = 0;
}