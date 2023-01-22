/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:50:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 18:28:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	free_parse(t_parse *parse)
{
	free_file(&parse->map.file);
	free_textures(&parse->textures);
	if (parse->map.matrix)
		ft_free_char_pp(parse->map.matrix);
	ft_get_next_line(-2, FT_NULL);
}
