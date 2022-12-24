/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/24 12:43:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_permission(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	return (file);
}

char	*get_line(int file)
{
	char	*ptr;
	int		last_char_index;

	ptr = ft_get_next_line(file);
	if (!ptr)
		return (FT_NULL);
	last_char_index = ft_strlen(ptr) - 1;
	if (ptr[last_char_index] == '\n')
		ptr[last_char_index] = 0;
	debug_print(PARSE_LINE, (void *)ptr);
	return (ptr);
}

int	parse_file_params(int file, t_parse *main)
{
	char	*line;
	int		return_value;

	line = get_line(file);
	if (!line)
		return (4);
	return_value = parse_line(line, main);
	if (return_value == 1)
		debug_print(PARSE_EMPTY_LINE, FT_NULL);
	else if (return_value)
		return (return_value);
	while (line)
	{
		free(line);
		line = get_line(file);
		return_value = parse_line(line, main);
		if (return_value == 1)
			debug_print(PARSE_EMPTY_LINE, FT_NULL);
		else if (return_value == -1)
			break ;
		else if (return_value)
			return (return_value);
	}
	return (0);
}

int	parse_file_map(int file, t_parse *main)
{
	debug_print(PARSE_PARAMS_DONE, NULL);
	return (-1);
}

int	parse_file(char *filename, t_parse *main)
{
	int		file;
	int		return_value;

	file = check_permission(filename);
	if (file < 0)
		return (3);
	return_value = parse_file_params(file, main);
	if (return_value && return_value != -1)
		return (return_value);
	return_value = parse_file_map(file, main);
	return (return_value);
}
