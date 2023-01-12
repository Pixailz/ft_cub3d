/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:44:29 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 16:09:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_r_value	parse_entry(char *filename, t_parse *parsing)
{
	if (parse_file_name(filename))
		return (1);
	if (parse_file(filename, parsing) != -1)
		return (1);
	return (0);
}
