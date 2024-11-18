/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr_pos_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:26:31 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 12:25:32 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_arr_pos_col(t_collect_pos *arr_pos_col)
{
	if (arr_pos_col != NULL)
		free(arr_pos_col);
}
