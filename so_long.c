/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:52:32 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/26 18:29:12 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Repara el git para poder subirlo a github!
// corre el pprograma y mira bugs

int		main(int argc, char *argv[])
{
	char	*map;
	
	n_arguments_ok(argc);
	map_is_ok(argv);
	map = get_map(argv);
	printf("\n%s\n", map);

/* 	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd)); */
}