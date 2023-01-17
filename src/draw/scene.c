/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:20:31 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 18:59:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_put_pixel(int x, int y, t_mlx_texture *image, t_int4 color)
{
	image->buff[x * 4 + 4 * y * image->len.x + 2] = \
												(int)ft_int4_dcomp(color, 1);
	image->buff[x * 4 + 4 * y * image->len.x + 1] = \
												(int)ft_int4_dcomp(color, 2);
	image->buff[x * 4 + 4 * y * image->len.x] = (int)ft_int4_dcomp(color, 3);
	return ;
}

void	draw_background(t_int4 floor, t_int4 ceiling, t_mlx_texture *scene)
{
	int	i;
	int	j;

	i = 0;
	while (i <= scene->len.y / 2)
	{
		j = 0;
		while (j <= scene->len.x)
		{
			ft_put_pixel(j, i, scene, ceiling);
			j++;
		}
		i++;
	}
	while (i <= scene->len.y)
	{
		j = 0;
		while (j <= scene->len.x)
		{
			ft_put_pixel(j, i, scene, floor);
			j++;
		}
		i++;
	}
}

void	reset_scene(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->textures.scene.ptr);
	mlx->textures.scene.ptr = mlx_new_image(mlx->ptr, \
											mlx->screen.x, mlx->screen.y);
	mlx->textures.scene.buff = mlx_get_data_addr(mlx->textures.scene.ptr, \
		&mlx->textures.scene.bpp, &mlx->textures.scene.size_line, \
		&mlx->textures.scene.endian);
}

void	draw_scene(t_main *config)
{
	t_ray	ray;

	ray = config->ray;
	if (RAYCAST_ENABLE)
		draw_raycast(config);
	if (config->player.pos.x / ray.text_size >= 0 && \
		config->player.pos.y / ray.text_size >= 0 && \
		config->player.pos.x / ray.text_size < config->parsing.map.size.x && \
		config->player.pos.y / ray.text_size < config->parsing.map.size.y)
	{
		draw_background(config->parsing.textures.floor, \
				config->parsing.textures.ceiling, &config->mlx.textures.scene);
	}
	cast_ray_entry(config);
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
		config->mlx.textures.scene.ptr, 0, 0);
	reset_scene(&config->mlx);
}
