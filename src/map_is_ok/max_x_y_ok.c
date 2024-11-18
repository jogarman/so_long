/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_x_y_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:27:26 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 13:48:29 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* x = 3840, y = 2160 
cells: (60.0, 33.75) - 2 of margin
*/
int	max_x_y_ok(char **map)
{
	int		x;
	int		y;

	x = ft_strlen((const char *)map[0]);
	y = y_max_arr(map);
	if ((x > 58 || y > 32))
	{
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}
