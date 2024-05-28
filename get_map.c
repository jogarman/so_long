/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:49:31 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/28 21:10:49 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		get_n_lines(fd)
{
	char	*line;
	int		n_columns;
	int		first_loop;
	int 	fd;

	n_columns = 0;
	first_loop = 1;
	while (first_loop == 1 || line != NULL)
	{
		first_loop = 0;
		line = get_next_line(fd);
		if (line != NULL)
			n_columns++;
	}
	free(line);
	close(fd);
	return (n_columns);
}

char	*get_map(char *argv[])
{
	char	*line;
	char	*map;
	int 	fd;
	int		first_loop;
	
	fd = ft_open(argv[1]);
	
	map = "";
	first_loop = 1;
	while (first_loop == 1 || line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			map = ft_strjoin(map, line);
		first_loop = 0;
	}
	free(line);
	close(fd);
	return (map);
}