/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:50:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:04:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	init_parsing(t_parse *parsing)
{
	init_file(&parsing->map.file);
	parsing->map.matrix = FT_NULL;
	init_textures(&parsing->textures);
}

void	free_parsing(t_parse *parsing)
{
	free_file(&parsing->map.file);
	free_textures(&parsing->textures);
	if (parsing->map.matrix)
		ft_free_char_pp(parsing->map.matrix);
	ft_get_next_line(-2, FT_NULL);
}
