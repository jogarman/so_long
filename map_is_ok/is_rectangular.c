/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:08:12 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/29 11:28:08 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		ft_strlen_without_last_br(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n') 
		return (ft_strlen(line) - 1);
	else
		return (ft_strlen(line));
}

/* si el ultimo caracter  no es salto de linea -> suma 1 a la longitud de la linea */
int		is_rectangular(char *argv[])
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
			line_len_1 = ft_strlen_without_last_br(line);
			if (i == 0)
				line_len_2 = line_len_1;
			if (line_len_2 != line_len_1)
				return (-1);
			i++;
			line_len_2 = line_len_1;
		}
	}
	free(line);
	close(fd);
	return (0);
}
