/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:20:31 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/21 15:02:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	draw_background(t_int4 floor, t_int4 ceiling, t_mlx_texture *scene)
{
	int	x;
	int	y;

	y = 0;
	while (y <= scene->len.y / 2)
	{
		x = 0;
		while (x <= scene->len.x)
			ft_put_pixel(x++, y, scene, ceiling);
		y++;
	}
	while (y <= scene->len.y)
	{
		x = 0;
		while (x <= scene->len.x)
			ft_put_pixel(x++, y, scene, floor);
		y++;
	}
}

// void	reset_scene(t_mlx *mlx)
// {
// 	mlx_destroy_image(mlx->ptr, mlx->textures.scene.ptr);
// 	mlx->textures.scene.ptr = mlx_new_image(mlx->ptr, 
// 											mlx->screen.x, mlx->screen.y);
// 	mlx->textures.scene.buff = mlx_get_data_addr(mlx->textures.scene.ptr, 
// 		&mlx->textures.scene.bpp, &mlx->textures.scene.size_line, 
// 		&mlx->textures.scene.endian);
// }

// screen.x * screen.y * scene.bpp {18874368}
// scene.size_line * scene.bpp{131072}
// size_line{4096}
// sizeof(scene.buff[0]){1}
// bpp{32}

void	reset_scene(t_main *config)
{
	int				lmemb_scene;
	int				test;
	t_mlx_texture	scene;

	test = sizeof(scene.buff[0]);
	scene = config->mlx.textures.scene;
	lmemb_scene = config->mlx.screen.y * scene.size_line;
	ft_memset(scene.buff, 0, lmemb_scene);
}

void	draw_scene(t_main *config)
{
	t_ray	ray;

	ray = config->ray;
	if (RAYCAST_ENABLE)
		draw_raycast(config);
	reset_scene(config);
	if (config->player.pos.x / ray.text_size >= 0 && \
		config->player.pos.y / ray.text_size >= 0 && \
		config->player.pos.x / ray.text_size < config->parse.map.size.x && \
		config->player.pos.y / ray.text_size < config->parse.map.size.y)
	{
		draw_background(config->parse.textures.floor, \
				config->parse.textures.ceiling, &config->mlx.textures.scene);
	}
	cast_ray_entry(config);
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
		config->mlx.textures.scene.ptr, 0, 0);
}
