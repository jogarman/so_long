/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_is_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:48:11 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/29 23:56:29 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
0123.ber -- 4-7 => strlen = 8
01234567 -- strlen - 4 = pos
*/
int	name_is_ok(char *map_name)
{
	int		i;
	int		j;
    char 	str[5];

    ft_strlcpy(str, ".ber", 5);
	i = ft_strlen(map_name) - 1;
	if (i <= 3)
	{
		ft_putstr_fd("map extension must be .ber", 2);
		return (-1);
	}

	i = ft_strlen(map_name) - 4;
	j = 0;
	while(map_name[i] != '\0' && str[j] != '\0' && map_name[i] == str[j])
	{
		i++;
		j++;
	}
	if (map_name[i] - str[j] == 0)
		return (0);
	else
		return (-1);
}
