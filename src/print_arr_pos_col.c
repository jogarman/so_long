/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr_pos_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:42:47 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/30 20:45:56 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_arr_pos_col(t_collect_pos *arr_pos_col, int n_col_ini)
{
	int n;

	printf("Posiciones de los coleccionables:\n");
	for (n = 0; n < n_col_ini; n++)
	{
		printf("Coleccionable %d: [%d, %d]\n", n + 1, arr_pos_col[n].pos_col[0], arr_pos_col[n].pos_col[1]);
	}
}
/*
print_arr_pos_col(game->arr_pos_col, game->n_collectables_ini);
*/
