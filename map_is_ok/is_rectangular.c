/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:08:12 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/29 00:47:05 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		is_rectangular(char *argv[], char **map)
{
	char	*line;
	int		i;
	int 	fd;
	int		line_len_1;
	int		line_len_2;
	
	fd = ft_open(argv[1]);
	i = 0;
	while (i == 0 || line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{

			line_len_1 = ft_strlen(line);
			if (i != 0)
				line_len_2 = line_len_1;
			if (line_len_2 != line_len_1)
			{
				return (-1);
			}
			i++;
			line_len_2 = line_len_1;
		}
	}
	//jft_print_vector(map);
	(void)map;
	free(line);
	close(fd);
	return (0);
}

