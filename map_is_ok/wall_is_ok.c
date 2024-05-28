/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_is_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:11:47 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/28 19:15:20 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	only_1_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
		{
			printf("only_1_line: line[i] = %c\n", line[i]);
			return (-1);
		}
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
	{
		return (-1);
	}
	while (line != NULL)
	{
		prev_line = ft_strdup(line);
		if ((line = get_next_line(fd)))
			if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
				return (-1);
	}
	if (only_1_in_line(prev_line) == -1)
	{
		return (-1);
	}
	free(line);
	close(fd);
	return (0);
}