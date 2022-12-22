/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:44:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 07:59:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_filename(char *filename)
{
	int	filename_len;

	filename_len = ft_strlen(filename) - 4;
	if (filename_len < 0)
		return (1);
	if (ft_strncmp(".cub", filename + filename_len, 4))
		return (2);
	return (0);
}

int	parse_entry(char *filename, t_config *main)
{
	int	return_value;

	return_value = parse_filename(filename);
	if (return_value)
		return (return_value);
	return_value = parse_file(filename, main);
	if (return_value)
		return (return_value);
	return (0);
}
