/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 04:21:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_l_pos	move_get_offset(t_player player, int text_size)
{
	t_l_pos	offset;

	offset.x = 0;
	offset.y = 0;
	if (player.delta.x < 0)
		offset.x = -HIT_OFFSET;
	else
		offset.x = HIT_OFFSET;
	if (player.delta.y < 0)
		offset.y = -HIT_OFFSET;
	else
		offset.y = HIT_OFFSET;
	offset.x = (player.pos.x + offset.x) / text_size;
	offset.y = (player.pos.y + offset.y) / text_size;
	return (offset);
}

void	key_press_move_left(t_player *player, int text_size, t_map map)
{
	t_l_pos	offset;

	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
	offset = move_get_offset(*player, text_size);
	if (map.matrix[(int)player->pos.y / text_size][offset.x] != WALL_CHAR)
		player->pos.x += player->delta.x;
	if (map.matrix[offset.y][(int)player->pos.x / text_size] != WALL_CHAR)
		player->pos.y += player->delta.y;
	player->angle += 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_right(t_player *player, int text_size, t_map map)
{
	t_l_pos	offset;

	player->angle += 90 * DR;
	adjust_delta(player, text_size);
	offset = move_get_offset(*player, text_size);
	if (map.matrix[(int)player->pos.y / text_size][offset.x] != WALL_CHAR)
		player->pos.x += player->delta.x;
	if (map.matrix[offset.y][(int)player->pos.x / text_size] != WALL_CHAR)
		player->pos.y += player->delta.y;
	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_up(t_player *player, int text_size, t_map map)
{
	t_l_pos	offset;

	offset = move_get_offset(*player, text_size);
	if (map.matrix[(int)player->pos.y / text_size][offset.x] != WALL_CHAR)
		player->pos.x += player->delta.x;
	if (map.matrix[offset.y][(int)player->pos.x / text_size] != WALL_CHAR)
		player->pos.y += player->delta.y;
}

void	key_press_move_down(t_player *player, int text_size, t_map map)
{
	t_l_pos	offset;

	offset = move_get_offset(*player, text_size);
	if (map.matrix[(int)player->pos.y / text_size][offset.x] != WALL_CHAR)
		player->pos.x -= player->delta.x;
	if (map.matrix[offset.y][(int)player->pos.x / text_size] != WALL_CHAR)
		player->pos.y -= player->delta.y;
}

// void	key_press_move_up(t_player *player, int text_size, t_map map)
// {
// 	t_i_pos	offset;

// 	offset = move_get_offset(*player, text_size);
// 	if (map.matrix[(int)player->pos.y / text_size][offset.x] != WALL_CHAR)
// 		player->pos.x += player->delta.x;
// 	if (map.matrix[offset.y][(int)player->pos.x / text_size] != WALL_CHAR)
// 		player->pos.y += player->delta.y;
// }

// void	key_press_move_down(t_player *player, int text_size, t_map map)
// {
// 	t_i_pos	offset;

// 	offset = move_get_offset(*player, text_size);
// 	if (map.matrix[(int)player->pos.y / text_size][offset.x] != WALL_CHAR)
// 		player->pos.x -= player->delta.x;
// 	if (map.matrix[offset.y][(int)player->pos.x / text_size] != WALL_CHAR)
// 		player->pos.y -= player->delta.y;
// }
