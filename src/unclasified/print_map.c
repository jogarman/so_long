/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:14:05 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/01 12:35:37 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_map(char **map)
{
	int i;
	if (map[0] == NULL || map == NULL)
	{
		ft_putstr_fd("print_map: map is null", 2);
		exit(1);
	}
	i = 0;
	while (map[i] != NULL)
	{
		write(1, map[i], ft_strlen(map[i]));
		i++;
	}
	write(1, "\n", 1);
}