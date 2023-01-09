/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:05:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 22:06:10 by brda-sil         ###   ########.fr       */
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
	text->ptr = mlx_xpm_file_to_image(mlx, file_path, \
													&text->len_x, &text->len_y);
	if (!text->ptr)
		return (1);
	return (0);
}

t_return_value	load_textures(t_main *config)
{
	if (load_texture(&config->mlx.north_text, \
			config->parsing.texture.north_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_05));
	if (load_texture(&config->mlx.south_text, \
			config->parsing.texture.south_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_06));
	if (load_texture(&config->mlx.west_text, \
			config->parsing.texture.west_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_07));
	if (load_texture(&config->mlx.east_text, \
			config->parsing.texture.east_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_08));
	if (load_texture(&config->mlx.mini_wall, \
			MINIMAP_WALL_PATH, config->mlx.ptr))
		return (set_error(0, ERRN_08));
	if (load_texture(&config->mlx.mini_void, \
			MINIMAP_VOID_PATH, config->mlx.ptr))
		return (set_error(0, ERRN_08));
	if (load_texture(&config->mlx.mini_player, \
			MINIMAP_PLAYER_PATH, config->mlx.ptr))
		return (set_error(0, ERRN_08));
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
