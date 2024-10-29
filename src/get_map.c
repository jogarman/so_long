/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:49:31 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/29 15:43:08 by jgarcia3         ###   ########.fr       */
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

	map = ft_calloc(get_n_lines(argv) + 1, sizeof(char *));
	//TODO protect
	fd = ft_open(argv[1]);
	i = 0;
    while ((line = get_next_line(fd)) != NULL && line[0] != '\n')
    {
        map[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
        if (!map[i])
        {
            free_map(map);
            free(line);
            close(fd);
            return NULL;
        }
        ft_memmove(map[i++], line, ft_strlen(line));
        free(line);
    }
    close(fd);
    return (map);
}


	/*line = get_next_line(fd);
  	while ((i == 0 || line != NULL) && line[0] != '\n') //con este codigo comentado hay 
															// + errores
	{
		map[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char)); //proteger
		if (!map[i])
			free_map(map, i);
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