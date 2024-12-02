/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:18:39 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/12/02 11:36:20 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

size_t	get_n_lines(char *argv[])
{
	char	*line;
	size_t	n_lines;
	int		first_loop;
	int		fd;

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
