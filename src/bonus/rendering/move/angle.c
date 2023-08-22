/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/24 13:13:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	adjust_delta(t_player *player, int text_size)
{
	player->delta.x = cos(player->angle) * text_size * PLAYER_STEP;
	player->delta.y = sin(player->angle) * text_size * PLAYER_STEP;
}

void	key_press_move_angle_left(t_player *player, int text_size)
{
	player->angle -= DR * (player->movement.r_speed * 4);
	if (player->angle < 0)
		player->angle += PI2;
	adjust_delta(player, text_size);
}

void	key_press_move_angle_right(t_player *player, int text_size)
{
	player->angle += DR * (player->movement.r_speed * 4);
	if (player->angle > PI2)
		player->angle -= PI2;
	adjust_delta(player, text_size);
}

void	key_press_move_angle_up(t_player *player)
{
	player->angle_y += DR * (player->movement.r_speed_y * 4);
	if (player->angle_y > 1)
		player->angle_y = 1;
}	

void	key_press_move_angle_down(t_player *player)
{
	player->angle_y -= DR * (player->movement.r_speed_y * 4);
	if (player->angle_y < 0)
		player->angle_y = 0;
}
