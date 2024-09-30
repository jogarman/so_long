/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:38 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/09/30 19:37:44 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	map_is_ok(argv);

	mlx_t *guardado = mlx_init(111, 111, "jajaj", true);
	mlx_loop(guardado);
}