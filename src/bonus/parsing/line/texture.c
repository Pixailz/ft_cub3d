/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 13:11:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	ft_is_space(const char c)
{
	return (c == ' ');
}

void	set_texture(t_error *err, t_file_l **text, char *path, int fd)
{
	if (!text)
		*text = lstnew_file(err, ft_strdup(path), fd);
	else
		lstadd_front_file(text, lstnew_file(err, ft_strdup(path), fd));
	if (errno != 0)
		errno = 0;
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
		set_texture(err, &parse->textures.north_file, ptr, file);
	else if (type == SOUTH)
		set_texture(err, &parse->textures.south_file, ptr, file);
	else if (type == WEST)
		set_texture(err, &parse->textures.west_file, ptr, file);
	else if (type == EAST)
		set_texture(err, &parse->textures.east_file, ptr, file);
	return (0);
}
