/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:20:31 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 03:35:54 by brda-sil         ###   ########.fr       */
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

void	draw_scene(t_main *config)
{
	if ((int)(config->player.pos.x / CELL_SIZE) >= 0 && \
		(int)(config->player.pos.y) / CELL_SIZE >= 0 && \
		(int)(config->player.pos.x / CELL_SIZE) < config->parsing.map.size.x && \
		(int)(config->player.pos.y / CELL_SIZE) < config->parsing.map.size.y && \
		config->parsing.map.matrix[(int)(config->player.pos.y / CELL_SIZE)] \
			[(int)(config->player.pos.x / CELL_SIZE)] != VOID_CHAR)
	{
		draw_background(config->parsing.textures.floor, \
				config->parsing.textures.ceiling, &config->mlx.textures.scene);
	}
	cast_ray_entry(config);
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
		config->mlx.textures.scene.ptr, 0, 0);
}
