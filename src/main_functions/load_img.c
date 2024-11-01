/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:58:55 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/01 18:38:44 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	finish_game_due_to_fail_in_textures(t_game *game)
{
	ft_putstr_fd("Fail loading textures", 2);
	free_map(game->map);
	free_arr_pos_col(game->arr_pos_col);
	//free_images(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}


/* Check if any problem has occur during texture loading */
static int	textures_ok(t_textures textures)
{
	if (
		textures.hero == NULL ||
		textures.collectable == NULL ||
		textures.exit == NULL ||
		textures.wall == NULL ||
		textures.floor == NULL)
		{
			return (-1);
		}
	else
		return (0);
}


t_img	load_img(mlx_t* mlx, t_game *game)
{
	t_textures	textures;
	t_img 		img;

	textures.hero = mlx_load_png("./textures/me.png");
	textures.collectable = mlx_load_png("./textures/money.png");
	textures.exit = mlx_load_png("./textures/plane.png");
	textures.wall = mlx_load_png("./textures/wall.png");
	textures.floor = mlx_load_png("./textures/floor.png");
	if (textures_ok(textures))
		finish_game_due_to_fail_in_textures(game);
	img.floor = mlx_texture_to_image(mlx, textures.floor);
	img.hero = mlx_texture_to_image(mlx, textures.hero);
	img.collectable = mlx_texture_to_image(mlx, textures.collectable);
	img.exit = mlx_texture_to_image(mlx, textures.exit);
	img.wall = mlx_texture_to_image(mlx, textures.wall);
	mlx_delete_texture(textures.hero);
	mlx_delete_texture(textures.collectable);
	mlx_delete_texture(textures.exit);
	mlx_delete_texture(textures.wall);
	mlx_delete_texture(textures.floor);
	return (img);
}
