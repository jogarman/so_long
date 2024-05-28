/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:55:20 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/26 17:10:25 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *name)
{
	int	fd;
	
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		perror("Error\nFile can not be opened");
		exit(EXIT_FAILURE);
	}
	return (fd);
}