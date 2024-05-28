/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:08:12 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/28 20:40:46 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		is_rectangular(char *argv[])
{
	char	*line;
	int		first_loop;
	int 	fd;
	int		line_len_1;
	int		line_len_2;
	
	fd = ft_open(argv[1]);
	first_loop = 1;
	while (first_loop == 1 || line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			line_len_1 = ft_strlen(line);
			if (first_loop)
				line_len_2 = line_len_1;
			if (line_len_2 != line_len_1)
				return (-1);
			first_loop = 0;
			line_len_2 = line_len_1;
		}
	}
	free(line);
	close(fd);
	return (0);
}

