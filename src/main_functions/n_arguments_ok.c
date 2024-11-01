/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_arguments_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:38:07 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/10/10 17:51:41 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* if number arguments ok, return 1, if not ok exit(-1)*/
void	n_arguments_ok(int n)
{
	if (n != 2)
	{
		printf("One argument must be provided\n");
		exit(EXIT_FAILURE);
	}
}