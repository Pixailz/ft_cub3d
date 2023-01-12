/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 20:12:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_file_name(t_error *err, char *filename)
{
	int				file_name_len;
	t_r_value		return_value;

	file_name_len = ft_strlen(filename) - 4;
	return_value = 0;
	if (file_name_len < 0)
		return_value |= set_error(err, 1, ERRN_01);
	if (ft_strncmp(".cub", filename + file_name_len, 4))
		return_value |= set_error(err, 1, ERRN_02);
	return (return_value);
}

t_bool	parse_file_is_empty(t_error *err, char **line, int fd)
{
	*line = parse_get_line(err, fd);
	if (!*line)
	{
		if (have_error(*err, 1) ^ ERRN_01)
			return (set_error(err, 1, ERRN_04));
		return (1);
	}
	return (0);
}

t_r_value	parse_file_params(t_error *err, t_parse *parsing)
{
	char	*line;
	int		return_value;

	if (parse_file_is_empty(err, &line, parsing->map_file.fd))
		return (1);
	if (parse_line(err, &line, parsing))
		return (1);
	while (TRUE)
	{
		line = parse_get_line(err, parsing->map_file.fd);
		return_value = parse_line(err, &line, parsing);
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

int	parse_file(t_error *err, char *filename, t_parse *parsing)
{
	int		return_value;

	return_value = 0;
	parsing->map_file.fd = check_permission(filename);
	if (parsing->map_file.fd < 0)
		return (set_error(err, 1, ERRN_03));
	return_value = parse_file_params(err, parsing);
	if (return_value && return_value != -1)
		return (return_value);
	if (have_error(*err, 2))
		return (1);
	debug_print(PARSE_PARAMS_DONE, NULL);
	return_value = parse_map(err, parsing);
	return (return_value);
}
