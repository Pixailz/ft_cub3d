/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 06:35:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	check_map_new_line(t_map map)
{
	int	counter;

	counter = 0;
	while (map.matrix[counter])
	{
		if (!ft_strncmp(map.matrix[counter], "\0", 1))
			return (TRUE);
		counter++;
	}
	return (FALSE);
}

t_bool	check_map_wrong_char(t_map map)
{
	t_i_pos	pos;

	pos.y = 0;
	while (map.matrix[pos.y])
	{
		pos.x = 0;
		while (map.matrix[pos.y][pos.x])
		{
			if (!ft_strchr(GOOD_CHAR_MAP, map.matrix[pos.y][pos.x++]))
				return (TRUE);
		}
		pos.y++;
	}
	return (FALSE);
}

int	check_map_player_char(t_map map, t_error *err)
{
	t_i_pos	pos;
	int		already_seen;

	pos.y = 0;
	already_seen = 0;
	while (map.matrix[pos.y])
	{
		pos.x = 0;
		while (map.matrix[pos.y][pos.x])
		{
			if (map_char_is_player(map.matrix[pos.y][pos.x]))
			{
				if (already_seen++)
					return (set_error(err, 1, ERRN_17));
			}
			pos.x++;
		}
		pos.y++;
	}
	if (!already_seen)
		return (set_error(err, 1, ERRN_18));
	return (0);
}

int	check_map_content(t_map *map, t_error *err)
{
	debug_print(PARSE_GET_MAP_SPLITTED, (void *)map->matrix);
	if (check_map_new_line(*map))
		return (set_error(err, 1, ERRN_14));
	if (check_map_wrong_char(*map))
		return (set_error(err, 1, ERRN_15));
	if (!check_is_surrounded_map(err, map))
		return (set_error(err, 1, ERRN_16));
	if (check_map_door_surrounded(*map, err))
		return (1);
	if (check_map_player_char(*map, err))
		return (1);
	return (-1);
}
