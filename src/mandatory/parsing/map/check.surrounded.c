/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 20:42:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

t_bool	check_is_surrounded_char_8(int x, int y, char **map)
{
	int		wall_check;
	int		dir_x;
	int		dir_y;
	char	current_char;

	debug_print_coord_checked(x, y, map);
	wall_check = 0;
	dir_x = -1;
	while (dir_x < 2)
	{
		dir_y = -1;
		while (dir_y < 2)
		{
			if (dir_x == 0 && dir_y == 0 && dir_y++)
				continue ;
			current_char = map[x + dir_x][y + dir_y];
			if (current_char == '1' || current_char == VOID_CHAR)
				wall_check++;
			dir_y++;
		}
		dir_x++;
	}
	return (wall_check == 8);
}

t_bool	check_is_surrounded_char_4(int x, int y, char **map)
{
	int		wall_check;
	char	current_char;

	debug_print_coord_checked(x, y, map);
	wall_check = 0;
	current_char = map[x + 1][y];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	current_char = map[x - 1][y];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	current_char = map[x][y + 1];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	current_char = map[x][y - 1];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	return (wall_check == 4);
}

t_bool	check_is_surrounded_map(t_map *map)
{
	char	**map_dup;
	int		counter_1;
	int		counter_2;

	get_map_size(map);
	map_dup = dup_map_surrounded(*map);
	counter_1 = 1;
	while (counter_1 < map->size.y + 3)
	{
		counter_2 = 0;
		while (++counter_2 < map->size.x + 3)
		{
			if (map_dup[counter_1][counter_2] == VOID_CHAR && \
				!check_is_surrounded_char_4(counter_1, counter_2, map_dup))
			{
				ft_free_char_pp(map_dup);
				return (FALSE);
			}
		}
		counter_1++;
	}
	ft_free_char_pp(map_dup);
	return (TRUE);
}
