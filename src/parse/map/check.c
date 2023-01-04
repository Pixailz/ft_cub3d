/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 05:28:39 by brda-sil         ###   ########.fr       */
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
					return (16);
			}
			counter_2++;
		}
		counter_1++;
	}
	if (!already_seen)
		return (17);
	return (0);
}

int	check_map_content(char **map)
{
	int	return_value;

	if (check_map_new_line(map))
		return (13);
	if (check_map_wrong_char(map))
		return (14);
	if (!check_is_surrounded_map(map))
		return (15);
	return_value = check_map_player_char(map);
	if (return_value)
		return (return_value);
	return (-1);
}
