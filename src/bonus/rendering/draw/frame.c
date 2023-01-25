/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:32:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 06:57:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	do_moving(t_main *config)
{
	if (config->player.movement.left == TRUE)
		key_press_move_left(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.right == TRUE)
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
	if (config->player.movement.right_angle == TRUE)
		key_press_move_angle_right(&config->player, config->ray.text_size);
}

int	draw_frame(t_main *config)
{
	do_moving(config);
	draw_scene(config);
	if (config->player.movement.reading_map)
		draw_minimap(config);
	usleep(ONE_SEC / FPS);
	return (0);
}
