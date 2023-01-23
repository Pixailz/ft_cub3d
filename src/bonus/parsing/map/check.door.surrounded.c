/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.door.surrounded.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 06:03:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 07:50:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	check_door_not_enclosed(t_i_pos pos, char **map)
{
	char	up;
	char	down;
	char	right;
	char	left;

	up = map[pos.y + 1][pos.x];
	down = map[pos.y - 1][pos.x];
	right = map[pos.y][pos.x + 1];
	left = map[pos.y][pos.x - 1];
	if (up == EMPTY_CHAR && down == EMPTY_CHAR && right == EMPTY_CHAR && \
															left == EMPTY_CHAR)
		return (TRUE);
	if (up == WALL_CHAR && down == EMPTY_CHAR && right == EMPTY_CHAR && \
															left == EMPTY_CHAR)
		return (TRUE);
	if (up == EMPTY_CHAR && down == WALL_CHAR && right == EMPTY_CHAR && \
															left == EMPTY_CHAR)
		return (TRUE);
	if (up == EMPTY_CHAR && down == EMPTY_CHAR && right == WALL_CHAR && \
															left == EMPTY_CHAR)
		return (TRUE);
	if (up == EMPTY_CHAR && down == EMPTY_CHAR && right == EMPTY_CHAR && \
															left == WALL_CHAR)
		return (TRUE);
	return (FALSE);
}

t_bool	check_door_obstructed(t_i_pos pos, char **map)
{
	t_i_pos	have;

	have.x = 0;
	have.y = 0;
	if (map[pos.y + 1][pos.x] == WALL_CHAR)
		have.y += 1;
	if (map[pos.y - 1][pos.x] == WALL_CHAR)
		have.y += 1;
	if (map[pos.y][pos.x + 1] == WALL_CHAR)
		have.x += 1;
	if (map[pos.y][pos.x - 1] == WALL_CHAR)
		have.x += 1;
	if ((have.y == 2 && have.x == 0) || (have.x == 2 && have.y == 0))
		return (FALSE);
	else
		return (TRUE);
}

int	check_door(t_i_pos pos, char **map, t_error *err)
{
	debug_print_coord_checked(pos, map);
	if (check_door_not_enclosed(pos, map))
		return (set_error(err, 1, ERRN_19));
	if (check_door_obstructed(pos, map))
		return (set_error(err, 1, ERRN_20));
	return (0);
}

int	check_map_door_surrounded(t_map map, t_error *err)
{
	t_i_pos	pos;
	int		r_value;

	pos.y = 0;
	r_value = 0;
	while (map.matrix[pos.y])
	{
		pos.x = 0;
		while (map.matrix[pos.y][pos.x])
		{
			if (map.matrix[pos.y][pos.x] == DOOR_CLOSE_CHAR)
				r_value = check_door(pos, map.matrix, err);
			pos.x++;
		}
		pos.y++;
	}
	return (r_value);
}
