/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:05:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 15:05:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_texture(t_texture *texture)
{
	init_file(&texture->north_file);
	init_file(&texture->south_file);
	init_file(&texture->west_file);
	init_file(&texture->east_file);
	texture->ceiling[0] = -1;
	texture->ceiling[1] = -1;
	texture->ceiling[2] = -1;
	texture->floor[0] = -1;
	texture->floor[1] = -1;
	texture->floor[2] = -1;
}

void	free_texture(t_texture *texture)
{
	texture->floor[0] = 0;
	texture->floor[1] = 0;
	texture->floor[2] = 0;
	texture->ceiling[0] = 0;
	texture->ceiling[1] = 0;
	texture->ceiling[2] = 0;
	free_file(&texture->north_file);
	free_file(&texture->south_file);
	free_file(&texture->west_file);
	free_file(&texture->east_file);
}
