/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:58:15 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 14:00:40 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_map_null(char *map)
{
	if (map == NULL || map[0] == '\n' || map[0] == '\0')
	{
		ft_putstr_fd("Error:\nMap is null or empty or invalid", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
