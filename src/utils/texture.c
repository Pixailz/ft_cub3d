/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:05:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 18:21:52 by brda-sil         ###   ########.fr       */
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
													&text->len.x, &text->len.y);
	if (!text->ptr)
		return (1);
	text->buff = mlx_get_data_addr(text->ptr, \
								&text->bpp, &text->size_line, &text->endian);
	return (0);
}

t_r_value	load_textures(t_main *config)
{
	if (load_texture(&config->mlx.textures.north, \
			config->parsing.textures.north_file.path, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, NORTH);
	if (load_texture(&config->mlx.textures.south, \
			config->parsing.textures.south_file.path, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, SOUTH);
	if (load_texture(&config->mlx.textures.west, \
			config->parsing.textures.west_file.path, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, WEST);
	if (load_texture(&config->mlx.textures.east, \
			config->parsing.textures.east_file.path, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, EAST);
	if (load_texture(&config->mlx.textures.mini_wall, \
			MINI_WALL_PATH, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_VOID);
	if (load_texture(&config->mlx.textures.mini_void, \
			MINI_VOID_PATH, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_WALL);
	if (load_texture(&config->mlx.textures.mini_player, \
			MINI_PLAYER_PATH, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_PLAYER);
	if (load_texture(&config->mlx.textures.mini_hit, \
			MINI_HIT_PATH, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_HIT);
	return (have_error(config->err, 4));
}

void	free_textures(t_textures *textures)
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
