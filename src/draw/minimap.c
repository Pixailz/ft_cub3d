/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:12:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 00:09:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_map_point(t_main *config, char current_cell, int y, int x)
{
	if (current_cell == '1')
		mlx_put_image_to_window(config->mlx.ptr, \
						config->mlx.win_raycasting, config->mlx.textures.mini_wall.ptr, \
						x * CELL_SIZE / (CELL_SIZE / MINI_CELL_SIZE), \
						y * CELL_SIZE / (CELL_SIZE / MINI_CELL_SIZE));
	else
		mlx_put_image_to_window(config->mlx.ptr, \
						config->mlx.win_raycasting, config->mlx.textures.mini_void.ptr, \
						x * CELL_SIZE / (CELL_SIZE / MINI_CELL_SIZE), \
						y * CELL_SIZE / (CELL_SIZE / MINI_CELL_SIZE));
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
	t_f_pos	pos;

	pos.x = get_ratio(config->player.pos.x) - MINI_PLAYER_SIZE / 2;
	pos.y = get_ratio(config->player.pos.y) - MINI_PLAYER_SIZE / 2;
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win_raycasting, \
		config->mlx.textures.mini_player.ptr, pos.x, pos.y);
}

void	draw_player_angle(t_main *config)
{
	t_f_pos	begin;
	t_f_pos	end;
	t_f_pos	delta;

	begin.x = get_ratio(config->player.pos.x);
	begin.y = get_ratio(config->player.pos.y);
	delta.x = cos(config->player.angle) * PLAYER_ANGLE_SIZE;
	delta.y = sin(config->player.angle) * PLAYER_ANGLE_SIZE;
	end.x = begin.x + delta.x;
	end.y = begin.y + delta.y;
	draw_line(config->mlx.ptr, config->mlx.win_raycasting, get_line(begin, end), \
			PLAYER_ANGLE_COLOR);
}

void	draw_minimap(t_main *config)
{
	draw_map(config);
	draw_player_pos(config);
	draw_player_angle(config);
}
