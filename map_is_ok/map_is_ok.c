/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:28:15 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/28 21:26:55 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		map_is_ok(char *argv[])
{
	int		n_rows;
	int		n_col;
	char	*one_line_map;

	one_line_map = get_one_line_map(argv);
	is_map_null(one_line_map);
	n_rows = get_n_rows(one_line_map); //pa que?

	printf("no_strange_obj: %d\n", no_strange_obj(one_line_map));
	printf("number objects ok: %d\n", ok_number_c_e_p(one_line_map));
	printf("is rectangular: %d\n", is_rectangular(argv));
	printf("wall_ok: %d\n", wall_ok(argv));
	
	(void)n_col;
	(void)n_col;
	return (n_rows);
}
