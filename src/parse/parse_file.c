/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/28 21:39:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_file_params(t_parse *main)
{
	char	*line;
	int		return_value;

	line = get_line(main->file);
	if (!line)
		return (4);
	return_value = parse_line(line, main);
	free(line);
	if (return_value == 1)
		debug_print(PARSE_EMPTY_LINE, FT_NULL);
	else if (return_value)
		return (return_value);
	while (TRUE)
	{
		line = get_line(main->file);
		return_value = parse_line(line, main);
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

int	parse_file(char *filename, t_parse *main)
{
	int		return_value;

	main->file = check_permission(filename);
	if (main->file < 0)
		return (3);
	return_value = parse_file_params(main);
	if (return_value && return_value != -1)
		return (return_value);
	debug_print(PARSE_PARAMS_DONE, NULL);
	return_value = parse_map(main);
	return (return_value);
}
