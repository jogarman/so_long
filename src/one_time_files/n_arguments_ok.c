/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_arguments_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:25:10 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/30 18:13:46 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	n_arguments_ok(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nBad arguments", 2);
		exit(EXIT_FAILURE);
	}
}