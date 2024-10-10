/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_x_y_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:27:26 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/10 23:01:58 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* x = 3840, y = 2160 
cells: (60.0, 33.75) - 2 of margin
*/
int		max_x_y_ok(char** map)
{
	int		x;
	int		y;

	x = (ft_strlen(map[0]));
	y = y_max_arr((const char**)map);
	printf("x = %d, y = %d\n", x, y);
	if ((x > 59 || y > 33))
	{
		printf("x: %d\n", x);
		printf("y: %d\n", y);
		return (1); 
	}
	return (0);
}