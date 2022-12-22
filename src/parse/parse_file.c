/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 08:29:56 by brda-sil         ###   ########.fr       */
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
	last_char_index = ft_strlen(ptr) - 1;
	if (ptr[last_char_index] == '\n')
		ptr[last_char_index] = 0;
	return (ptr);
}

int	parse_file_content(int file, t_config *main)
{
	char	*line;
	int		return_value;

	line = get_line(file);
	ft_printf("line[0] [%s]\n", line);
	if (!line)
		return (4);
	return_value = parse_line(line, main);
	if (return_value == 1)
		ft_printf("Empty line\n");
	else if (return_value)
		return (return_value + 3);
	while (line)
	{
		free(line);
		line = get_line(file);
		ft_printf("line[] [%s]\n", line);
		return_value = parse_line(line, main);
		if (return_value == 1)
			ft_printf("Empty line\n");
		else if (return_value)
			return (return_value + 3);
	}
	return (0);
}

int	parse_file(char *filename, t_config *main)
{
	int		file;
	int		return_value;

	file = check_permission(filename);
	if (file < 0)
		return (3);
	return_value = parse_file_content(file, main);
	if (return_value)
		return (return_value);
	return (0);
}
