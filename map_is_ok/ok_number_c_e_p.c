/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_number_c_e_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:05:13 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/28 19:05:21 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		ok_number_c_e_p(char *map)
{
	int	i;
	int	c;
	int	e;
	int	p;
	
	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			c++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'P')
			p++;
		i++;
	}
	if (c > 0 && e == 1 && p == 1)
		return (0);
	else 
		return (-1);
}
