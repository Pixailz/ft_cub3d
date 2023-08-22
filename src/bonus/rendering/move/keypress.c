/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/27 01:23:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	key_press_move_left(t_player *player, int text_size, t_map map)
{
	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
	move_dir_forward(player, text_size, map);
	player->angle += 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_right(t_player *player, int text_size, t_map map)
{
	player->angle += 90 * DR;
	adjust_delta(player, text_size);
	move_dir_forward(player, text_size, map);
	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_up(t_player *player, int text_size, t_map map)
{
	move_dir_forward(player, text_size, map);
}

void	key_press_move_down(t_player *player, int text_size, t_map map)
{
	move_dir_backward(player, text_size, map);
}

void	key_press_interact_down(t_main *config)
{
	t_d_pos	sp;
	int		mx;
	int		my;

	config->ray.angle = config->player.angle;
	config->ray.hit_door = 0;
	if (config->ray.angle < 0)
		config->ray.angle += PI2;
	if (config->ray.angle > PI2)
		config->ray.angle -= PI2;
	config->ray.a_tan = get_a_tan(config->ray.angle);
	config->ray.n_tan = get_n_tan(config->ray.angle);
	cast_ray_up(&config->ray, config->player);
	cast_ray_down(&config->ray, config->player);
	sp.x = config->ray.pos.x;
	sp.y = config->ray.pos.y;
	cast_ray_left(&config->ray, config->player);
	cast_ray_right(&config->ray, config->player);
	if (get_dist(config->player.pos, config->ray.pos) < get_dist(config->player.pos, sp))
	{
		sp.x = config->ray.pos.x;
		sp.y = config->ray.pos.y;
	}
	mx = (int)(sp.x / config->ray.text_size);
	my = (int)(sp.y / config->ray.text_size);
	if (sp.x >= 0 && sp.y >= 0)
	{
		if (mx < config->parse.map.size.x + MAX_DOF && \
			my < config->parse.map.size.y + MAX_DOF)
		{
			if (config->parse.map.matrix[my][mx] == DOOR_CLOSE_CHAR)
				config->parse.map.matrix[my][mx] = DOOR_OPEN_CHAR;
			else if (config->parse.map.matrix[my][mx] == DOOR_OPEN_CHAR)
				config->parse.map.matrix[my][mx] = DOOR_CLOSE_CHAR;
		}
	}
}
