/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:44:29 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:26:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_file_name(char *filename)
{
	int	file_name_len;

	file_name_len = ft_strlen(filename) - 4;
	if (file_name_len < 0)
		return (1);
	if (ft_strncmp(".cub", filename + file_name_len, 4))
		return (2);
	return (0);
}

int	parse_entry(char *filename, t_parse *parsing)
{
	int	return_value;

	return_value = parse_file_name(filename);
	if (return_value)
		return (return_value);
	return_value = parse_file(filename, parsing);
	return (return_value);
}
