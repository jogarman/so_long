/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:59:24 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/29 17:16:47 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void keyhook(mlx_key_data_t keydata, void *params)
{
	t_game	*game;
	
	game = params;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
	{
		try_to_mv(game, 'a');
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
	{
		try_to_mv(game, 'w');
	}	
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
	{
		try_to_mv(game, 's');
	}
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
	{
		try_to_mv(game, 'd');
	}
	if ((keydata.key == MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	ft_putstr_fd("hola",1);
}
