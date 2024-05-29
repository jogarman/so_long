/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:49:31 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 00:10:31 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



size_t	get_n_columns(char *argv[])
{
	size_t	n_columns;
	int 	fd;
	char	*line;
	
	fd = ft_open(argv[1]);
	line = get_next_line(fd);
	n_columns = ft_strlen(line);
	free(line);
	close(fd);
	return (n_columns);
}

size_t		get_n_lines(char *argv[])
{
	char	*line;
	size_t	n_lines;
	int		first_loop;
	int 	fd;

	fd = ft_open(argv[1]);
	n_lines = 0;
	first_loop = 1;
	while (first_loop == 1 || line != NULL)
	{
		if (first_loop == 0)
			free(line);
		first_loop = 0;
		line = get_next_line(fd);
		if (line != NULL)
			n_lines++;
	}
	free(line);
	close(fd);
	return (n_lines);
}

/* 
bug if characters after empty line 
free function is necesary to clean sub-strings
*/
char	**get_map(char *argv[])
{
	char	*line;
	char	**map;
	int 	fd;
	int		i;

	map = ft_calloc(get_n_lines(argv), sizeof(char *)); //proteger
	fd = ft_open(argv[1]); //proteger
	i = 0;
/*	line = get_next_line(fd);
 	while ((i == 0 || line != NULL) && line[0] != '\n')
	{
		map[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char)); //proteger
		if (!map[i])
			map_free(**map, i);
 		if (line != NULL && line[ft_strlen(line) - 1] == '\n')
			ft_memmove(map[i], line, ft_strlen(line) - 1);
		if (line != NULL && line[ft_strlen(line) - 1] != '\n')
			ft_memmove(map[i], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (map);
} */
    while ((line = get_next_line(fd)) != NULL && line[0] != '\n')
    {
        map[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
        if (!map[i])
        {
            free_map(map, i);
            free(line);
            close(fd);
            return NULL;
        }
        ft_memmove(map[i], line, ft_strlen(line));
        free(line);
        i++;
    }

    free(line);
    close(fd);
    return map;
}


