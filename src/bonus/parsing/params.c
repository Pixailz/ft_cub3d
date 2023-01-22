/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:33:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 03:19:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

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

t_r_value	parse_file_params(t_error *err, t_parse *parse)
{
	char	*line;
	int		return_value;

	if (parse_file_is_empty(err, &line, parse->map.file.fd))
		return (1);
	if (parse_line(err, &line, parse))
		return (1);
	while (TRUE)
	{
		line = parse_get_line(err, parse->map.file.fd);
		return_value = parse_line(err, &line, parse);
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
