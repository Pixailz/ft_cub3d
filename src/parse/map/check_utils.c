/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:53:55 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 19:24:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

char	*dup_map_get_line(int width, char *line)
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
		duplicated[counter] = dup_map_get_line(width, map[counter - 2]);
		counter++;
	}
	debug_print(PARSE_GET_MAP_SURROUDED, (void *)duplicated);
	return (duplicated);
}
