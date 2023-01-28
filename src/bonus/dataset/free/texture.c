/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:46:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/27 00:52:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	free_textures(t_textures *textures)
{
	textures->ceiling = ft_int4_comp(0, 0, 0, 0);
	textures->floor = ft_int4_comp(0, 0, 0, 0);
	free_file_list(textures->north_file);
	free_file_list(textures->south_file);
	free_file_list(textures->west_file);
	free_file_list(textures->east_file);
}
