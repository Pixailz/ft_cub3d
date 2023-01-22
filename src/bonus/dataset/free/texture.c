/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:46:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 03:19:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	free_textures(t_textures *textures)
{
	textures->ceiling = ft_int4_comp(0, 0, 0, 0);
	textures->floor = ft_int4_comp(0, 0, 0, 0);
	free_file(&textures->north_file);
	free_file(&textures->south_file);
	free_file(&textures->west_file);
	free_file(&textures->east_file);
}
