/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 16:33:07 by brda-sil         ###   ########.fr       */
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
	if (ptr)
	{
		last_char_index = ft_strlen(ptr) - 1;
		if (ptr[last_char_index] == '\n')
			ptr[last_char_index] = 0;
	}
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

int	parse_file_map(t_parse *main)
{
	int r_value;
	int w;
	int h;
	char **check_map;

	w = 0;
	h = 0;
	get_map_size(main->map, &h, &w);
	check_map = create_check_map(main->map);
	if (!check_map)
		return(15);
	r_value = check_map_is_good(check_map);
	if (r_value)
	{
		ft_free_char_pp(check_map);
		return(12);
	}
	ft_free_char_pp(main->map);
	init_check_map(check_map, h, w, ' ');
	main->map = check_map;
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
	return_value = parse_file_map(main);
	return (return_value);
}

