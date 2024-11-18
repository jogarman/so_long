/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_empty_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:25:31 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/18 13:51:52 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	no_empty_lines(char *one_line_map)
{
	char	prev_char;
	int		i;

	i = 0;
	while (one_line_map[i] != '\0')
	{
		prev_char = one_line_map[i];
		one_line_map++;
		if (prev_char == '\n' && one_line_map[0] == '\n')
			return (-1);
	}
	return (0);
}
