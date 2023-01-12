/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:05:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_textures(t_textures *texture)
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

t_r_value	load_texture(t_mlx_texture *text, char *file_path, void *mlx)
{
	text->ptr = mlx_xpm_file_to_image(mlx, file_path, \
													&text->len_x, &text->len_y);
	if (!text->ptr)
		return (1);
	return (0);
}

t_r_value	load_textures(t_main *config)
{
	if (load_texture(&config->mlx.textures.north, \
			config->parsing.textures.north_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_05));
	if (load_texture(&config->mlx.textures.south, \
			config->parsing.textures.south_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_06));
	if (load_texture(&config->mlx.textures.west, \
			config->parsing.textures.west_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_07));
	if (load_texture(&config->mlx.textures.east, \
			config->parsing.textures.east_file.path, config->mlx.ptr))
		return (set_error(0, ERRN_08));
	if (load_texture(&config->mlx.textures.mini_wall, \
			MINIMAP_WALL_PATH, config->mlx.ptr))
		return (set_error(0, ERRN_08));
	if (load_texture(&config->mlx.textures.mini_void, \
			MINIMAP_VOID_PATH, config->mlx.ptr))
		return (set_error(0, ERRN_08));
	if (load_texture(&config->mlx.textures.mini_player, \
			MINIMAP_PLAYER_PATH, config->mlx.ptr))
		return (set_error(0, ERRN_08));
	return (0);
}

void	free_textures(t_textures	*textures)
{
	textures->floor[0] = 0;
	textures->floor[1] = 0;
	textures->floor[2] = 0;
	textures->ceiling[0] = 0;
	textures->ceiling[1] = 0;
	textures->ceiling[2] = 0;
	free_file(&textures->north_file);
	free_file(&textures->south_file);
	free_file(&textures->west_file);
	free_file(&textures->east_file);
}
