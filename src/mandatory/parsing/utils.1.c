/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:50:52 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/21 02:47:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

/**
 * @brief			open file and return fd.
 *
 * @param [in] char*	filename
 *
 * @return			(int) fd on success and -1 on fail.
 */
int	check_permission(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	return (file);
}

t_bool	map_char_is_player(char c)
{
	if (c == 'N')
		return (TRUE);
	else if (c == 'S')
		return (TRUE);
	else if (c == 'E')
		return (TRUE);
	else if (c == 'W')
		return (TRUE);
	return (FALSE);
}

void	get_map_size(t_map *map)
{
	int	max_x;

	max_x = 0;
	map->size.y = 0;
	while (map->matrix[map->size.y])
	{
		map->size.x = 0;
		while (map->matrix[map->size.y][map->size.x])
		{
			map->size.x++;
			if (max_x < map->size.x)
				max_x = map->size.x;
		}
		map->size.y++;
	}
	map->size.x = max_x;
	debug_print(PARSE_MAP_SIZE, (void *)map);
}

char	*dup_map_get_line_2(int width, char *line)
{
	char	*formated_line;
	int		counter;

	formated_line = ft_calloc(sizeof(char), width + 5);
	formated_line[0] = VOID_CHAR;
	formated_line[1] = VOID_CHAR;
	formated_line[2] = VOID_CHAR;
	ft_strcpy(formated_line + 2, line);
	counter = 1;
	while (formated_line[counter])
		if (formated_line[counter++] == ' ')
			formated_line[counter - 1] = VOID_CHAR;
	counter = width + 3;
	while (!formated_line[counter])
		formated_line[counter--] = VOID_CHAR;
	return (formated_line);
}

char	**dup_map_surrounded(t_map map)
{
	int		counter;
	char	**duplicated;

	duplicated = (char **)ft_calloc(sizeof(char *), map.size.y + 5);
	duplicated[0] = (char *)ft_calloc(sizeof(char), map.size.x + 5);
	duplicated[1] = (char *)ft_calloc(sizeof(char), map.size.x + 5);
	ft_memset((void *)duplicated[0], VOID_CHAR, map.size.x + 4);
	ft_memset((void *)duplicated[1], VOID_CHAR, map.size.x + 4);
	duplicated[map.size.y + 2] = ft_strdup(duplicated[0]);
	duplicated[map.size.y + 3] = ft_strdup(duplicated[0]);
	counter = 2;
	while (counter < map.size.y + 2)
	{
		duplicated[counter] = \
						dup_map_get_line_2(map.size.x, map.matrix[counter - 2]);
		counter++;
	}
	debug_print(PARSE_GET_MAP_SURROUDED, (void *)duplicated);
	return (duplicated);
}
