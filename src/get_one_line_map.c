/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:19:42 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 00:22:27 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
char	*get_one_line_map(char *argv[], char *fd)
fd value is nor important. Just *norminette*
*/
char	*get_one_line_map(char *argv[], int fd)
{
	char	*line;
	char	*map;
	char	*map_2;
	int		first_loop;
	
	fd = ft_open(argv[1]);
	map = "";
	first_loop = 1;
	while (first_loop == 1 || line != NULL)
	{
		if (first_loop == 0)
			free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			map_2 = ft_calloc((ft_strlen(map) + 1), sizeof(char));
			ft_strlcpy(map_2, map, ft_strlen(map));
			if (first_loop == 0)
				free(map);
			map = ft_strjoin(map_2, line);
			free(map_2);
		}
		first_loop = 0;
	}
	return (free(line), close(fd), map);
}
