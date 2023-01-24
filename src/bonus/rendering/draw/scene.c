/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:20:31 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/24 05:27:17 by brda-sil         ###   ########.fr       */
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
	float	x_x;
	float	y_y;

	ray = config->ray;
	x_x = config->player.pos.x / ray.text_size;
	y_y = config->player.pos.y / ray.text_size;
	if (RAY_ENABLE)
		draw_raycast(config);
	ft_memset(config->mlx.textures.scene.buff, 0, \
				config->mlx.screen.y * config->mlx.textures.scene.size_line);
	if (x_x >= MAX_DOF && y_y >= MAX_DOF && \
								x_x < config->parse.map.size.x + MAX_DOF && \
								y_y < config->parse.map.size.y + MAX_DOF)
	{
		draw_background(config->parse.textures.floor, \
				config->parse.textures.ceiling, &config->mlx.textures.scene);
	}
	cast_ray_entry(config);
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
		config->mlx.textures.scene.ptr, 0, 0);
}
