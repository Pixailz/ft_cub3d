/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 05:40:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_map_size(int *height, int *width, char **map)
{
	int	max_width;

	max_width = 0;
	*height = 0;
	while (map[*height])
	{
		*width = 0;
		while (map[*height][*width])
		{
			(*width)++;
			if (max_width < *width)
				max_width = *width;
		}
		(*height)++;
	}
	*width = max_width;
}

char	*dup_map_get_line(int width, int height, char *line)
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

char	**dup_map(char **map)
{
	int		counter;
	int		height;
	int		width;
	char	**duplicated;

	get_map_size(&height, &width, map);
	duplicated = (char **)ft_calloc(sizeof(char *), height + 5);
	duplicated[0] = (char *)ft_calloc(sizeof(char), width + 5);
	duplicated[1] = (char *)ft_calloc(sizeof(char), width + 5);
	ft_memset((void *)duplicated[0], VOID_CHAR, width + 4);
	ft_memset((void *)duplicated[1], VOID_CHAR, width + 4);
	duplicated[height + 2] = ft_strdup(duplicated[0]);
	duplicated[height + 3] = ft_strdup(duplicated[0]);
	counter = 2;
	while (counter < height + 2)
	{
		duplicated[counter] = dup_map_get_line(width, height, map[counter - 2]);
		counter++;
	}
	debug_print(PARSE_GET_MAP_SURROUDED, (void *)duplicated);
	return (duplicated);
}

t_bool	check_is_surrounded_char(int x, int y, char **map)
{
	int	wall_check;

	wall_check = 0;
	if (map[x + 1][y] == '1')
		wall_check++;
	if (map[x - 1][y] == '1')
		wall_check++;
	if (map[x][y + 1] == '1')
		wall_check++;
	if (map[x][y - 1] == '1')
		wall_check++;
	if (wall_check == 4)
		return (TRUE);
	return (FALSE);
}

t_bool	check_is_surrounded_map(char **map)
{
	char	**map_dup;
	int		counter_1;
	int		counter_2;

	map_dup = dup_map(map);
	counter_1 = 1;
	while (map_dup[counter_1])
	{
		counter_2 = 1;
		while (map_dup[counter_1][counter_2])
		{
			if (map_dup[counter_1][counter_2] == '0' && \
				!check_is_surrounded_char(counter_1, counter_2, map_dup))
			{
				ft_free_char_pp(map_dup);
				return (FALSE);
			}
			counter_2++;
		}
		counter_1++;
	}
	ft_free_char_pp(map_dup);
	return (TRUE);
}
