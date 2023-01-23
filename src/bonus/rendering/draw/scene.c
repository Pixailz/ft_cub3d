/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:20:31 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 04:05:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

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

void	draw_scene(t_main *config)
{
	t_ray	ray;

	ray = config->ray;
	if (RAY_ENABLE)
		draw_raycast(config);
	ft_memset(config->mlx.textures.scene.buff, 0, \
				config->mlx.screen.y * config->mlx.textures.scene.size_line);
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
