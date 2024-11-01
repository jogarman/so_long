/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_is_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:48:11 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/11/01 18:37:30 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_get_max(int s1, int s2)
{
	if (s1 < s2)
		return (s2);
	else
		return (s1);
}

static int	ft_str_equals(const char *s1, const char *s2)
{
	return (!ft_strncmp(s1, s2, ft_get_max(ft_strlen(s1), ft_strlen(s2))));
} 

/*
Chech if name is something like:
"folder_name/.ber"
because it is not a valid name
@returns 
*/
static int	is_fourth_last_char_a_bar(char *map_name)
{
	int		pos;
	char	*ptr;

	ptr = ft_strrchr(map_name, '/');
	if (ptr == NULL)
	{
		ptr = "";
	}
	pos = ft_strlen(ptr);
	if (pos == 5)
	{
		return 1;
	}
	return (0);
}

/*
@returns 0  ok
@returns -1 error
*/
int			name_is_ok(char *map_name)
{
	if (ft_str_equals(map_name, ".ber"))
		return (-1);
	if (is_fourth_last_char_a_bar(map_name))
		return (-1);
	else
		return (0);

}

/*
	int		i;
	int		j;
    char 	str[5];
	




	
	i = ft_strlen(map_name) - 1;
	i = ft_strlen(map_name) - 4;
	j = 0;
	while(map_name[i] != '\0' && str[j] != '\0' && map_name[i] == str[j])
	{
		i++;
		j++;
	}
	if (map_name[i] - str[j] == 0)
		return (0);
	else
		return (-1);
		
*/