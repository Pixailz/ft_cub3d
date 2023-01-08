/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 22:52:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	check_map_new_line(char **map)
{
	int	counter;

	counter = 0;
	while (map[counter])
	{
		if (!ft_strncmp(map[counter], "\0", 1))
			return (TRUE);
		counter++;
	}
	return (FALSE);
}

t_bool	check_map_wrong_char(char **map)
{
	int		counter_1;
	int		counter_2;

	counter_1 = 0;
	counter_2 = 0;
	while (map[counter_1])
	{
		counter_2 = 0;
		while (map[counter_1][counter_2])
		{
			if (!ft_strchr(GOOD_CHAR_MAP, map[counter_1][counter_2++]))
				return (TRUE);
		}
		counter_1++;
	}
	return (FALSE);
}

int	check_map_player_char(char **map)
{
	int	counter_1;
	int	counter_2;
	int	already_seen;

	counter_1 = 0;
	counter_2 = 0;
	already_seen = 0;
	while (map[counter_1])
	{
		counter_2 = 0;
		while (map[counter_1][counter_2])
		{
			if (map_char_is_player(map[counter_1][counter_2]))
			{
				if (already_seen++)
					return (set_error(1, ERRN_17));
			}
			counter_2++;
		}
		counter_1++;
	}
	if (!already_seen)
		return (set_error(1, ERRN_18));
	return (0);
}

int	check_map_content(char **map)
{
	debug_print(PARSE_GET_MAP_SPLITTED, (void *)map);
	if (check_map_new_line(map))
		return (set_error(1, ERRN_14));
	if (check_map_wrong_char(map))
		return (set_error(1, ERRN_15));
	if (!check_is_surrounded_map(map))
		return (set_error(1, ERRN_16));
	if (check_map_player_char(map))
		return (1);
	return (-1);
}
