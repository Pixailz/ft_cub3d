/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 17:27:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	adjust_delta(t_player *player)
{
	player->delta.x = cos(player->angle) * CELL_SIZE * PLAYER_STEP;
	player->delta.y = sin(player->angle) * CELL_SIZE * PLAYER_STEP;
}

void	key_press_move_angle_left(t_player *player)
{
	player->angle -= 0.1;
	if (player->angle < 0)
		player->angle += PI2;
	adjust_delta(player);
	debug_print(RENDER_PLAYER, (void *)player);
}

void	key_press_move_angle_right(t_player *player)
{
	player->angle += 0.1;
	if (player->angle > PI2)
		player->angle -= PI2;
	adjust_delta(player);
	debug_print(RENDER_PLAYER, (void *)player);
}
