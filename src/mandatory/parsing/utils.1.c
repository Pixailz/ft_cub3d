/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:50:52 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 03:22:52 by brda-sil         ###   ########.fr       */
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
