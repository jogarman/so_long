/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:54:21 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/26 17:20:44 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct parse_err
{
	char	*row_err;
}	parse_err;

/******* n_arguments ********/
void	n_arguments_ok(int argc);

/*******  map_is_ok  ********/
int		map_is_ok(char *argv[]);
int		ok_number_c_e_p(char *map);

char	*get_map(char *argv[]);
int		get_n_columns(char *argv[]);
int		get_n_rows(char *map);
int		is_rectangular(char *argv[]);
int		is_map_null(char *map);
/******** ft_open ***********/
int		ft_open(char *argv);