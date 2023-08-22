/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:47:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 08:21:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	init_textures(t_textures *texture)
{
	texture->north_file = FT_NULL;
	texture->south_file = FT_NULL;
	texture->west_file = FT_NULL;
	texture->east_file = FT_NULL;
	texture->ceiling = ft_int4_comp(0, 0, 0, 0);
	texture->floor = ft_int4_comp(0, 0, 0, 0);
}
