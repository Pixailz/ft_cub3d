/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 16:24:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	ft_is_space(const char c)
{
	return (c == ' ');
}

int	parse_line_texture(char *line, int line_type, t_parse *parsing)
{
	char	*ptr;
	int		file;

	if (line[2] != ' ' && line[2] != 0)
		return (7);
	else if (ft_is_str(line + 2, ft_is_space))
		return (8);
	ptr = line + 2;
	while (ft_is_space(*ptr))
		ptr++;
	file = check_permission(ptr);
	if (file < 0)
		return (0xff + (line_type << 8));
	else
	{
		if (line_type == NORTH)
			parsing->north_file_path = ft_strdup(ptr);
		else if (line_type == SOUTH)
			parsing->south_file_path = ft_strdup(ptr);
		else if (line_type == WEST)
			parsing->west_file_path = ft_strdup(ptr);
		else if (line_type == EAST)
			parsing->east_file_path = ft_strdup(ptr);
	}
	return (0);
}
