/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:05:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 02:01:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_textures(t_texture *texture)
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

t_return_value	load_texture(t_mlx_texture *text, char *file_path, void *mlx)
{
	text->ptr = mlx_xpm_to_image(mlx, &file_path, &text->len_x, &text->len_y);
	if (!text->ptr)
		return (1);
	return (0);
}

t_return_value	load_textures(t_main *config)
{
	if (load_texture(&config->mlx.north_text, \
			config->parsing.texture.north_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_04));
	if (load_texture(&config->mlx.south_text, \
			config->parsing.texture.south_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_05));
	if (load_texture(&config->mlx.north_text, \
			config->parsing.texture.north_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_06));
	if (load_texture(&config->mlx.north_text, \
			config->parsing.texture.north_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_07));
	return (0);
}

void	free_textures(t_texture *texture)
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
