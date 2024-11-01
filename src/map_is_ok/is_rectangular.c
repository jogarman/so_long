/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:08:12 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/01 14:55:52 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/**
 * @brief counts len
 * 
 * @param line line to count
 * @return number of characters
 */
int		ft_strlen_without_last_br(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n') 
		return (ft_strlen(line) - 1);
	else
		return (ft_strlen(line));
}

/*
@return 
* 0 if ok
* -1 if it's not rectangular
*/
int		is_rectangular(char *argv[])
{
	char	*line;
	int		i;
	int 	fd;
	int		line_len_2;
	int		return_status;
	
	return_status = 0;
	fd = ft_open(argv[1]);
	i = 0;
	while (i == 0 || line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (i == 0)
				line_len_2 = ft_strlen_without_last_br(line);
			if (line_len_2 != ft_strlen_without_last_br(line))
			{
				return_status = -1;
			}
			i++;
			line_len_2 = ft_strlen_without_last_br(line);
		}
		free(line);
	}
	close(fd);
	return (return_status);
}
