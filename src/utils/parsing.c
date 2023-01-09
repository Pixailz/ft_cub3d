/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:50:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 01:46:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_parsing(t_parse *parsing)
{
	init_file(&parsing->map_file);
	parsing->map = FT_NULL;
	init_textures(&parsing->texture);
}

void	free_parsing(t_parse *parsing)
{
	free_file(&parsing->map_file);
	free_textures(&parsing->texture);
	if (parsing->map)
		ft_free_char_pp(parsing->map);
	ft_get_next_line(-2, FT_NULL);
}
