/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map_squared.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:31:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 22:22:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

char	*dup_map_get_line(int width, char *line, int offset)
{
	char	*formated_line;
	int		counter;

	formated_line = ft_calloc(sizeof(char), width + offset * 2 + 1);
	counter = 0;
	while (counter < offset)
		formated_line[counter++] = VOID_CHAR;
	ft_strcpy(formated_line + offset, line);
	counter = offset;
	while (counter < width + offset * 2)
	{
		if (formated_line[counter] != WALL_CHAR && \
			formated_line[counter] != EMPTY_CHAR && \
			!map_char_is_player(formated_line[counter]))
			formated_line[counter] = VOID_CHAR;
		counter++;
	}
	counter = width + offset * 2;
	while (counter > width + offset)
		formated_line[--counter] = VOID_CHAR;
	return (formated_line);
}

void	dup_map_get_surrounding(char **dup, int offset, t_map map)
{
	int	offset_x_2;
	int	counter;

	offset_x_2 = 2 * offset;
	counter = 0;
	while (counter < offset)
	{
		dup[counter] = \
				(char *)ft_calloc(sizeof(char), map.size.x + offset_x_2 + 1);
		ft_memset((void *)dup[counter], VOID_CHAR, map.size.x + offset_x_2);
		dup[map.size.y + offset + counter] = ft_strdup(dup[0]);
		counter++;
	}
}

char	**dup_map_squared(t_map map, int offset)
{
	int		counter;
	char	**dup;

	if (offset < 0)
		return (FT_NULL);
	dup = (char **)ft_calloc(sizeof(char *), map.size.y + 1 + offset * 2);
	dup_map_get_surrounding(dup, offset, map);
	counter = offset;
	while (counter < map.size.y + offset)
	{
		dup[counter] = \
					dup_map_get_line(map.size.x, map.matrix[counter - offset], \
					offset);
		counter++;
	}
	debug_print(PARSE_GET_MAP_SURROUDED, (void *)dup);
	return (dup);
}
