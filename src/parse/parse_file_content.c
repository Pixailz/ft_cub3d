/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:03:40 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/19 19:29:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_file_line(char *line)
{
	if ()
		;
	return (0);
}

int	parse_file_content(int file, t_config *main)
{
	char	*line;

	line = ft_get_next_line(file);
	if (!line)
		return (4);
	parse_file_line(line);
}
