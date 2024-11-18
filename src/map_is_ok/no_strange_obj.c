/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_strange_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:03:02 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 13:59:59 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*Detects if  any other character is present. Exit() if True 0, 1, C, E, P \n */
int	no_strange_obj(char	*map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' && map[i] != 'E'
			&& map[i] != 'P' && map[i] != '\n')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
