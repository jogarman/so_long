/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:55:20 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/29 23:20:31 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	fd = ft_open(argv[1]); */
int	ft_open(char *name)
{
	int	fd;
	
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		perror("Error\nFile can not be open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}