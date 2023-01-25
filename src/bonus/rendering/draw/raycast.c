/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:12:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 05:47:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_map_point(t_main *config, char current_cell, int y, int x)
{
	t_ray	ray;

	ray = config->ray;
	if (current_cell == WALL_CHAR)
		mlx_put_image_to_window(config->mlx.ptr, \
			config->mlx.win_raycasting, config->mlx.textures.mini_wall.ptr, \
			x * ray.text_size / (ray.text_size / ray.mini_cell_size), \
			y * ray.text_size / (ray.text_size / ray.mini_cell_size));
	else if (current_cell == DOOR_CLOSE_CHAR)
		mlx_put_image_to_window(config->mlx.ptr, config->mlx.win_raycasting, \
			config->mlx.textures.mini_door_close.ptr, \
			x * ray.text_size / (ray.text_size / ray.mini_cell_size), \
			y * ray.text_size / (ray.text_size / ray.mini_cell_size));
	else if (current_cell == DOOR_OPEN_CHAR)
		mlx_put_image_to_window(config->mlx.ptr, config->mlx.win_raycasting, \
			config->mlx.textures.mini_door_open.ptr, \
			x * ray.text_size / (ray.text_size / ray.mini_cell_size), \
			y * ray.text_size / (ray.text_size / ray.mini_cell_size));
	else
		mlx_put_image_to_window(config->mlx.ptr, \
			config->mlx.win_raycasting, config->mlx.textures.mini_void.ptr, \
			x * ray.text_size / (ray.text_size / ray.mini_cell_size), \
			y * ray.text_size / (ray.text_size / ray.mini_cell_size));
}

void	draw_map(t_main *config)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = config->parse.map.matrix;
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
											config->ray.mini_player_size / 2;
	pos.y = get_ratio(config->player.pos.y, config->ray) - \
											config->ray.mini_player_size / 2;
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win_raycasting, \
		config->mlx.textures.mini_player.ptr, pos.x, pos.y);
}

void	draw_player_angle(t_main *config)
{
	t_line	line;
	t_d_pos	delta;

	line.begin.x = get_ratio(config->player.pos.x, config->ray);
	line.begin.y = get_ratio(config->player.pos.y, config->ray);
	delta.x = cos(config->player.angle) * PLAYER_ANGLE_SIZE;
	delta.y = sin(config->player.angle) * PLAYER_ANGLE_SIZE;
	line.end.x = line.begin.x + delta.x;
	line.end.y = line.begin.y + delta.y;
	line.color = PLAYER_ANGLE_COLOR;
	draw_line(config->mlx.ptr, config->mlx.win_raycasting, line);
}

void	draw_raycast(t_main *config)
{
	draw_map(config);
	draw_player_pos(config);
	draw_player_angle(config);
}
