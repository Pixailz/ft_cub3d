/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 20:47:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_file_name(char *filename)
{
	int				file_name_len;
	t_return_value	return_value;

	file_name_len = ft_strlen(filename) - 4;
	return_value = 0;
	if (file_name_len < 0)
		return_value |= set_error(1, ERRN_01);
	if (ft_strncmp(".cub", filename + file_name_len, 4))
		return_value |= set_error(1, ERRN_02);
	return (return_value);
}

t_bool	parse_file_is_empty(char **line, int fd)
{
	*line = parse_get_line(fd);
	if (!*line)
	{
		if (have_error(1) ^ ERRN_01)
			return (set_error(1, ERRN_04));
		return (1);
	}
	return (0);
}

t_return_value	parse_file_params(t_parse *parsing)
{
	char	*line;
	int		return_value;

	if (parse_file_is_empty(&line, parsing->map_file.fd))
		return (1);
	if (parse_line(&line, parsing))
		return (1);
	while (TRUE)
	{
		line = parse_get_line(parsing->map_file.fd);
		return_value = parse_line(&line, parsing);
		free(line);
		if (return_value == 1)
			continue ;
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

	return_value = 0;
	parsing->map_file.fd = check_permission(filename);
	if (parsing->map_file.fd < 0)
		return (set_error(1, ERRN_03));
	return_value = parse_file_params(parsing);
	if (return_value && return_value != -1)
		return (return_value);
	debug_print(PARSE_PARAMS_DONE, NULL);
	return_value = parse_map(parsing);
	return (return_value);
}
