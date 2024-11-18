/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2_dimensions_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:28:31 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 13:47:47 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**get_2_dimensions_map(char *argv[])
{
	size_t	i;
	int		fd;
	char	**map;
	char	*line;
	size_t	n_lines;

	n_lines = (int)get_n_lines(argv);
	map = malloc(sizeof(char *) * n_lines);
	fd = ft_open(argv[1]);
	i = 0;
	while (i != n_lines)
	{
		line = get_next_line(fd);
		map[i] = malloc(sizeof(char) * ft_strlen(line));
		map[i] = line;
		i++;
	}
	map[i] = '\0';
	close(fd);
	return (map);
}
