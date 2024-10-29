/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:07:11 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/29 17:07:19 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
int	try_to_mv(t_game *game, char direction)
{
	int		desired_next_xy[2];
	char	obj_next_pos;

	if (direction == 'a')
	{
		desired_next_xy[0] = game->p_pos[0] - 1;
		desired_next_xy[1] = game->p_pos[1];
	}
	if (direction == 'w')
	{
		desired_next_xy[0] = game->p_pos[0];
		desired_next_xy[1] = game->p_pos[1] - 1;
	}
	if (direction == 's')
	{
		desired_next_xy[0] = game->p_pos[0];
		desired_next_xy[1] = game->p_pos[1] + 1;
	}
	if (direction == 'd')
	{
		desired_next_xy[0] = game->p_pos[0] + 1;
		desired_next_xy[1] = game->p_pos[1];
	}
	print_map(game->map);

	obj_next_pos = obj_in_pos(game, desired_next_xy[0], desired_next_xy[1]);
	move_hero(game, desired_next_xy[0], desired_next_xy[1], obj_next_pos);
	return (1);
}