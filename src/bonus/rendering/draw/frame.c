/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:32:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 04:09:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	do_moving(t_main *config)
{
	if (config->player.movement.left == TRUE)
		key_press_move_left(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.rigth == TRUE)
		key_press_move_right(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.up == TRUE)
		key_press_move_up(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.down == TRUE)
		key_press_move_down(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.left_angle == TRUE)
		key_press_move_angle_left(&config->player, config->ray.text_size);
	if (config->player.movement.rigth_angle == TRUE)
		key_press_move_angle_right(&config->player, config->ray.text_size);
}

int	draw_frame(t_main *config)
{
	static int	frame_id = 0;

	frame_id++;
	if (frame_id > 500)
	{
		do_moving(config);
		draw_scene(config);
		frame_id = 0;
	}
	return (0);
}