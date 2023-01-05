/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:15:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_file_params(t_parse *parsing)
{
	char	*line;
	int		return_value;

	line = get_line(parsing->map_fd);
	if (!line)
		return (4);
	return_value = parse_line(line, parsing);
	free(line);
	if (return_value == 1)
		debug_print(PARSE_EMPTY_LINE, FT_NULL);
	else if (return_value)
		return (return_value);
	while (TRUE)
	{
		line = get_line(parsing->map_fd);
		return_value = parse_line(line, parsing);
		free(line);
		if (return_value == 1)
			debug_print(PARSE_EMPTY_LINE, FT_NULL);
		else if (return_value == -1)
			break ;
		else if (return_value)
			return (return_value);
	}
	return (0);
}

int	parse_file(char *filename, t_parse *parsing)
{
	int		return_value;

	parsing->map_fd = check_permission(filename);
	if (parsing->map_fd < 0)
		return (3);
	return_value = parse_file_params(parsing);
	if (return_value && return_value != -1)
		return (return_value);
	debug_print(PARSE_PARAMS_DONE, NULL);
	return_value = parse_map(parsing);
	return (return_value);
}
