/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:28:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/31 17:36:46 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

mlx_t* create_window(char* title, char** map)
{
	mlx_t*	mlx;
	int		height;
	int		width;
	
	height = (ft_strlen(map[0]) - 1) * CAVAS_SIZE;
	width = y_max_arr((char**)map) * CAVAS_SIZE;
	
	mlx = mlx_init(height, width, title, false);
	if (!mlx)
		error();
	return (mlx);
}