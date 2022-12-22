/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 08:24:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_line_texture(char *line, int line_type, t_config *main)
{
	char	*ptr;
	int		file;

	if (!ft_isblank(line[2]))
		return (1);
	else if (ft_is_str(line + 2, ft_isblank))
		return (2);
	ptr = line + 2;
	while (ft_isblank(*ptr))
		ptr++;
	file = check_permission(ptr);
	if (file < 0)
		return (3);
	else
	{
		if (line_type == 1)
			main->north_file = file;
		else if (line_type == (1 << 1))
			main->south_file = file;
		else if (line_type == (1 << 2))
			main->west_file = file;
		else if (line_type == (1 << 3))
			main->east_file = file;
	}
		close(file);
	return (0);
}
