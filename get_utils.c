/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:19:42 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/28 22:26:18 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_one_line_map(char *argv[])
{
	char	*line;
	char	*map;
	int 	fd;
	int		first_loop;
	
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("Error\nFile can not be opened");
		exit(EXIT_FAILURE);
	}
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


int		get_n_rows(char *map)
{
	int		n_rows;
	char	*break_pos;
	
	if (map == NULL || map[0] == '\n' || map[0] == '\0')
	{
		ft_putstr_fd("get_n_rows failed", 2);
		exit(EXIT_FAILURE);
	}
	break_pos = ft_strchr((const char*) map, '\n');
	n_rows = break_pos - map;
	return n_rows;
}