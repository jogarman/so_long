/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2_dimensions_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:28:31 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/11 13:07:51 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* only for testing purposes */
void print_2_dimensions_map(char **map) 
{
    int i = 0;

    while (map[i] != NULL)
    {
        printf("%s\n", map[i]);
        i++;
    }
}

char	**get_2_dimensions_map(char *argv[])
{
	size_t	i;
	int 	fd;
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
	//print_2_dimensions_map(map);
	map[i] = '\0';
	close(fd);
	return (map);
}