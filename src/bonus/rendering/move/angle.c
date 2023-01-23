/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 02:17:32 by brda-sil         ###   ########.fr       */
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
	debug_print(RENDER_PLAYER, (void *)player);
}

void	key_press_move_angle_right(t_player *player, int text_size)
{
	player->angle += DR * (player->movement.r_speed * 4);
	if (player->angle > PI2)
		player->angle -= PI2;
	adjust_delta(player, text_size);
	debug_print(RENDER_PLAYER, (void *)player);
}
