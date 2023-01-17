/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 19:04:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	key_press_move_left(t_player *player, int text_size)
{
	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
	player->pos.x += player->delta.x;
	player->pos.y += player->delta.y;
	player->angle += 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_right(t_player *player, int text_size)
{
	player->angle += 90 * DR;
	adjust_delta(player, text_size);
	player->pos.x += player->delta.x;
	player->pos.y += player->delta.y;
	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_up(t_player *player)
{
	player->pos.x += player->delta.x;
	player->pos.y += player->delta.y;
}

void	key_press_move_down(t_player *player)
{
	player->pos.x -= player->delta.x;
	player->pos.y -= player->delta.y;
}
