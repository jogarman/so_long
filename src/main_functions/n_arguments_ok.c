/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_arguments_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:38:07 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 13:38:18 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* if number arguments ok, return 1, if not ok exit(-1)*/
void	n_arguments_ok(int n)
{
	if (n != 2)
	{
		ft_putstr_fd("One argument must be provided\n", 2);
		exit(EXIT_FAILURE);
	}
}
