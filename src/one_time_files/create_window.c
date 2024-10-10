/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:28:45 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/10 18:46:58 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


mlx_t* create_window(char* title)
{
	mlx_t* mlx;

	mlx = mlx_init(WIDTH, HEIGHT, title, true);
	if (!mlx)
		error();
	return (mlx);
}