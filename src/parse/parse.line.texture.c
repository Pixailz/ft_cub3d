/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.line.texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	ft_is_space(const char c)
{
	return (c == ' ');
}

t_r_value	parse_line_texture(char *line, int line_type, t_parse *parsing)
{
	char	*ptr;
	int		file;

	if (line[2] != ' ' && line[2] != 0)
		return (set_error_args(line_type, ERRN_07));
	else if (ft_is_str(line + 2, ft_is_space))
		return (set_error_args(line_type, ERRN_08));
	ptr = line + 2;
	while (ft_is_space(*ptr))
		ptr++;
	file = check_permission(ptr);
	if (file < 0)
		return (set_error_args(line_type, ERRN_09));
	else
	{
		if (line_type == NORTH)
			set_file(&parsing->textures.north_file, ft_strdup(ptr), file);
		else if (line_type == SOUTH)
			set_file(&parsing->textures.south_file, ft_strdup(ptr), file);
		else if (line_type == WEST)
			set_file(&parsing->textures.west_file, ft_strdup(ptr), file);
		else if (line_type == EAST)
			set_file(&parsing->textures.east_file, ft_strdup(ptr), file);
	}
	return (0);
}
