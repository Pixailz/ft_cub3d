/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 07:33:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	check_is_surrounded_char_8(t_i_pos pos, char **map)
{
	int		wall_check;
	int		dir_x;
	int		dir_y;
	char	current_char;

	debug_print_coord_checked(pos, map);
	wall_check = 0;
	dir_y = -1;
	while (dir_y < 2)
	{
		dir_x = -1;
		while (dir_x < 2)
		{
			if (dir_y == 0 && dir_x == 0 && dir_x++)
				continue ;
			current_char = map[pos.y + dir_y][pos.x + dir_x];
			if (current_char == '1' || current_char == VOID_CHAR)
				wall_check++;
			dir_x++;
		}
		dir_y++;
	}
	return (wall_check == 8);
}

t_bool	check_is_surrounded_char_4(t_i_pos pos, char **map)
{
	int		wall_check;
	char	current_char;

	debug_print_coord_checked(pos, map);
	wall_check = 0;
	current_char = map[pos.y + 1][pos.x];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	current_char = map[pos.y - 1][pos.x];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	current_char = map[pos.y][pos.x + 1];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	current_char = map[pos.y][pos.x - 1];
	if (current_char == WALL_CHAR || current_char == VOID_CHAR)
		wall_check++;
	return (wall_check == 4);
}

t_bool	check_is_surrounded_map(t_error *err, t_map *map)
{
	char	**map_dup;
	t_i_pos	pos;

	get_map_size(map);
	map_dup = dup_map_squared(*map, 2);
	debug_print(PARSE_GET_MAP_SURROUDED, (void *)map_dup);
	if (!map_dup)
		return (set_error(err, 0, ERRN_04));
	pos.y = 0;
	while (++pos.y < map->size.y + 3)
	{
		pos.x = 0;
		while (++pos.x < map->size.x + 3)
		{
			if (map_dup[pos.y][pos.x] == VOID_CHAR && \
									!check_is_surrounded_char_4(pos, map_dup))
			{
				ft_free_char_pp(map_dup);
				return (FALSE);
			}
		}
	}
	ft_free_char_pp(map_dup);
	return (TRUE);
}
