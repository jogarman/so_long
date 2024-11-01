/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_is_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:11:47 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/01 15:12:43 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	int	only_1_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}



int			wall_ok(char *argv[])
{
	char	*line;
	int 	fd;
	char	*prev_line;
	
	fd = ft_open(argv[1]);
	line = get_next_line(fd);
	if (only_1_in_line(line) == -1)
		return (-1);
	prev_line = ft_strdup(line);
	while (line != NULL)
	{
		free(prev_line);
		prev_line = ft_strdup(line);
		free(line);
		if ((line = get_next_line(fd)))
			if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
				return (free(line), free(prev_line), close(fd), -1);
	}
	if (only_1_in_line(prev_line) == -1)
		return (free(line), free(prev_line), close(fd), -1);
	free(line);
	free(prev_line);
	close(fd);
	return (0);
}
