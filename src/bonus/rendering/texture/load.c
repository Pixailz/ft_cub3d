/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:10:43 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 08:28:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

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

void	load_textures_minimap(t_mlx *mlx, t_error *err)
{
	if (load_texture(&mlx->textures.mini_wall, MINI_WALL_PATH, mlx->ptr))
		set_error_known(err, 1, ERRN_03, MINI_VOID);
	if (load_texture(&mlx->textures.mini_void, MINI_VOID_PATH, mlx->ptr))
		set_error_known(err, 1, ERRN_03, MINI_WALL);
	if (load_texture(&mlx->textures.mini_player, MINI_PLAYER_PATH, mlx->ptr))
		set_error_known(err, 1, ERRN_03, MINI_PLAYER);
	if (load_texture(&mlx->textures.mini_door_close, MINI_DOOR_CLOSE_PATH, \
																	mlx->ptr))
		set_error_known(err, 1, ERRN_03, MINI_DOOR_CLOSE);
	if (load_texture(&mlx->textures.mini_door_open, MINI_DOOR_OPEN_PATH, \
																	mlx->ptr))
		set_error_known(err, 1, ERRN_03, MINI_DOOR_OPEN);
}

t_r_value	load_textures(t_main *config)
{
	t_textures	*textures;
	t_mlx		*mlx;

	textures = &config->parse.textures;
	mlx = &config->mlx;
	if (load_texture(&mlx->textures.north, textures->north_file->file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, NORTH);
	if (load_texture(&mlx->textures.south, textures->south_file->file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, SOUTH);
	if (load_texture(&mlx->textures.west, textures->west_file->file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, WEST);
	if (load_texture(&mlx->textures.east, textures->east_file->file.path, mlx->ptr))
		set_error_known(&config->err, 1, ERRN_03, EAST);
	load_textures_minimap(mlx, &config->err);
	if (load_scene(config))
		set_error(&config->err, 3, ERRN_04);
	get_textures_size(config);
	return (have_error(config->err, 4));
}
