/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:28:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 13:37:00 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

mlx_t	*create_window(char *title, char **map)
{
	mlx_t	*mlx;
	int		height;
	int		width;

	height = (ft_strlen(map[0]) - 1) * SIZE;
	width = y_max_arr((char **)map) * SIZE;
	mlx = mlx_init(height, width, title, false);
	if (!mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	return (mlx);
}
