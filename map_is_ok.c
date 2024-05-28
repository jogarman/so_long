/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:28:15 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/26 18:18:59 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_map_null(char *map)
{
	if (map == NULL || map[0] == '\n'|| map[0] == '\0')
	{
		ft_putstr_fd("Error:\nMap is null or empty or invalid", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/*Detects if  any other character is present. Exit() if True 0, 1, C, E, P \n */
int		no_strange_obj(char	*map)
{
	int	i;
	
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' && map[i] != 'E' &&
			map[i] != 'P' && map[i] != '\n')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
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

/*
cargar la linea
si es la primera- segunda = primera
*/
int		is_rectangular(char *argv[])
{
	char	*line;
	int		first_loop;
	int 	fd;
	int		line_len_1;
	int		line_len_2;
	
	fd = ft_open(argv[1]);
	first_loop = 1;
	while (first_loop == 1 || line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			line_len_1 = ft_strlen(line);
			if (first_loop)
				line_len_2 = line_len_1;
			if (line_len_2 != line_len_1)
				return (-1);
			first_loop = 0;
			line_len_2 = line_len_1;
		}
	}
	free(line);
	close(fd);
	return (0);
}

int		only_1_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' || line[i] != '\0')
	{
		if (line[i] != 1)
			return (-1);
	}
	return (0);
}

int		wall_ok(char *argv[])
{
	char	*line;
	int 	fd;
	//int		error;
	char	*prev_line;
	
	fd = ft_open(argv[1]);
	line = get_next_line(fd);
	if (only_1_in_line(line) == -1)
		return (-1);
	while (line != NULL)
	{
		prev_line = ft_strdup(line);
		line = get_next_line(fd);
		if (line[0] != 1 || line[ft_strlen(line)] != 1)
			return (-1);
		printf("line[ft_strlen(line)]-> %c\n", line[ft_strlen(line)]);
	}
	prev_line = ft_strdup(line);
	if (only_1_in_line(prev_line) == -1)
		return (-1);
	free(line);
	close(fd);
	return (0);
}

int		map_is_ok(char *argv[])
{
	int		n_rows;
	int		n_col;
	char	*map;

	map = get_map(argv);
	is_map_null(map);
	n_rows = get_n_rows(map); //pa que?
	n_col = get_n_columns(argv); //pa qué?
	printf("no_strange_obj: %d\n", no_strange_obj(map));
	printf("number objects ok: %d\n", ok_number_c_e_p(map));
	printf("is rectangular: %d\n", is_rectangular(argv));
	printf("wall_ok: %d\n", wall_ok(argv));
	
	(void)n_col;
	(void)n_col;
	return (n_rows);
}