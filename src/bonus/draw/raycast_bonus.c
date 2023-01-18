/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:12:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:03:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_map_point(t_main *config, char current_cell, int y, int x)
{
	t_ray	ray;

	ray = config->ray;
	if (current_cell == '1')
		mlx_put_image_to_window(config->mlx.ptr, \
			config->mlx.win_raycasting, config->mlx.textures.raycast_wall.ptr, \
			x * ray.text_size / (ray.text_size / ray.raycast_cell_size), \
			y * ray.text_size / (ray.text_size / ray.raycast_cell_size));
	else
		mlx_put_image_to_window(config->mlx.ptr, \
			config->mlx.win_raycasting, config->mlx.textures.raycast_void.ptr, \
			x * ray.text_size / (ray.text_size / ray.raycast_cell_size), \
			y * ray.text_size / (ray.text_size / ray.raycast_cell_size));
}

void	draw_map(t_main *config)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = config->parsing.map.matrix;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_map_point(config, map[y][x], y, x);
			x++;
		}
		y++;
	}
}

void	draw_player_pos(t_main *config)
{
	t_d_pos	pos;

	pos.x = get_ratio(config->player.pos.x, config->ray) - \
											config->ray.raycast_player_size / 2;
	pos.y = get_ratio(config->player.pos.y, config->ray) - \
											config->ray.raycast_player_size / 2;
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win_raycasting, \
		config->mlx.textures.raycast_player.ptr, pos.x, pos.y);
}

void	draw_player_angle(t_main *config)
{
	t_d_pos	begin;
	t_d_pos	end;
	t_d_pos	delta;

	begin.x = get_ratio(config->player.pos.x, config->ray);
	begin.y = get_ratio(config->player.pos.y, config->ray);
	delta.x = cos(config->player.angle) * PLAYER_ANGLE_SIZE;
	delta.y = sin(config->player.angle) * PLAYER_ANGLE_SIZE;
	end.x = begin.x + delta.x;
	end.y = begin.y + delta.y;
	draw_line(config->mlx.ptr, config->mlx.win_raycasting, \
									get_line(begin, end), PLAYER_ANGLE_COLOR);
}

void	draw_raycast(t_main *config)
{
	draw_map(config);
	draw_player_pos(config);
	draw_player_angle(config);
}
