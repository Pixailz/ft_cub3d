/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:05:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 01:46:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_textures(t_textures *texture)
{
	init_file(&texture->north_file);
	init_file(&texture->south_file);
	init_file(&texture->west_file);
	init_file(&texture->east_file);
	texture->ceiling = ft_int4_comp(0, 0, 0, 0);
	texture->floor = ft_int4_comp(0, 0, 0, 0);
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

t_r_value	load_scene(t_main *config)
{
	t_mlx_texture	*scene;

	scene = &config->mlx.textures.scene;
	scene->len.x = config->mlx.screen.x;
	scene->len.y = config->mlx.screen.y;
	scene->ptr = mlx_new_image(config->mlx.ptr, scene->len.x, scene->len.y);
	if (!scene->ptr)
		return (1);
	scene->buff = mlx_get_data_addr(scene->ptr, &scene->bpp, \
											&scene->size_line, &scene->endian);
	if (!scene->buff)
		return (1);
	return (0);
}

t_r_value	load_textures(t_main *config)
{
	t_textures	*textures;
	t_mlx		*mlx;

	textures = &config->parsing.textures;
	mlx = &config->mlx;
	if (load_texture(&mlx->textures.north, textures->north_file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, NORTH);
	if (load_texture(&mlx->textures.south, textures->south_file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, SOUTH);
	if (load_texture(&mlx->textures.west, textures->west_file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, WEST);
	if (load_texture(&mlx->textures.east, textures->east_file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, EAST);
	if (load_texture(&mlx->textures.mini_wall, MINI_WALL_PATH, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_VOID);
	if (load_texture(&mlx->textures.mini_void, MINI_VOID_PATH, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_WALL);
	if (load_texture(&mlx->textures.mini_player, MINI_PLAYER_PATH, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_PLAYER);
	if (load_texture(&mlx->textures.mini_hit, MINI_HIT_PATH, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, MINI_HIT);
	if (load_scene(config))
		set_error(&config->err, 3, ERRN_04);
	return (have_error(config->err, 4));
}

void	free_textures(t_textures *textures)
{
	textures->ceiling = ft_int4_comp(0, 0, 0, 0);
	textures->floor = ft_int4_comp(0, 0, 0, 0);
	free_file(&textures->north_file);
	free_file(&textures->south_file);
	free_file(&textures->west_file);
	free_file(&textures->east_file);
}
