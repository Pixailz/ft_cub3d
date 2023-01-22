/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 03:19:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	ft_is_space(const char c)
{
	return (c == ' ');
}

t_r_value	parse_line_text(t_error *err, char *line, int type, t_parse *parse)
{
	char	*ptr;
	int		file;

	if (line[2] != ' ' && line[2] != 0)
		return (set_error_known(err, 0, ERRN_07, type));
	else if (ft_is_str(line + 2, ft_is_space))
		return (set_error_known(err, 0, ERRN_08, type));
	ptr = line + 2;
	while (ft_is_space(*ptr))
		ptr++;
	file = check_permission(ptr);
	if (file < 0)
		set_error_known(err, 0, ERRN_09, type);
	if (type == NORTH)
		set_file(&parse->textures.north_file, ft_strdup(ptr), file);
	else if (type == SOUTH)
		set_file(&parse->textures.south_file, ft_strdup(ptr), file);
	else if (type == WEST)
		set_file(&parse->textures.west_file, ft_strdup(ptr), file);
	else if (type == EAST)
		set_file(&parse->textures.east_file, ft_strdup(ptr), file);
	return (0);
}
