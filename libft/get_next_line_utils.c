/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:21:46 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/05/26 00:09:40 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Takes s1 y s2, and returns s1 + s2, in s1 consider leaks
*/
char	*merge(char *s1, char *s2, int len_prev_line)
{
	char	*temp;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	temp = ft_strdup_len_prev_line(s1, len_prev_line);
	free(s1);
	s1 = malloc((len_prev_line + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	i = -1;
	while (temp[++i])
		s1[i] = temp[i];
	j = 0;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	free(temp);
	return (s1);
}

/* void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*pointer;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	pointer = malloc(size * count);
	i = 0;
	if (pointer == 0)
		return (NULL);
	while (i < count * size)
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
} */

/* size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s && s[i] != '\0')
	{
		i++;
	}
	return (i);
} */

char	*ft_strdup_len_prev_line(const char *s1, int len_prev_line)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_calloc(len_prev_line + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while ((int)i < len_prev_line)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
