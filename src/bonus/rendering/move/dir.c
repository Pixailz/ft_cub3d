/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 15:04:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	hit_wall(t_player player, t_map map, int text_size)
{
	int	pos_x_text_size;
	int	pos_y_text_size;

	pos_x_text_size = player.pos.x / text_size;
	pos_y_text_size = player.pos.y / text_size;
	if (COLLISION)
		return (FALSE);
	if (pos_x_text_size >= 0 && pos_y_text_size >= 0)
	{
		if (pos_x_text_size < map.size.x && pos_y_text_size < map.size.y)
		{
			if (map.matrix[pos_y_text_size][pos_x_text_size] == WALL_CHAR)
				return (TRUE);
			if (map.matrix[pos_y_text_size][pos_x_text_size] == 'D')
				return (TRUE);
		}
	}
	return (FALSE);
}

void	key_press_move_left(t_player *player, int text_size, t_map map)
{
	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
	player->pos.x += player->delta.x;
	if (hit_wall(*player, map, text_size))
		player->pos.x -= player->delta.x;
	player->pos.y += player->delta.y;
	if (hit_wall(*player, map, text_size))
		player->pos.y -= player->delta.y;
	player->angle += 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_right(t_player *player, int text_size, t_map map)
{
	player->angle += 90 * DR;
	adjust_delta(player, text_size);
	player->pos.x += player->delta.x;
	if (hit_wall(*player, map, text_size))
		player->pos.x -= player->delta.x;
	player->pos.y += player->delta.y;
	if (hit_wall(*player, map, text_size))
		player->pos.y -= player->delta.y;
	player->angle -= 90 * DR;
	adjust_delta(player, text_size);
}

void	key_press_move_up(t_player *player, int text_size, t_map map)
{
	player->pos.x += player->delta.x;
	if (hit_wall(*player, map, text_size))
		player->pos.x -= player->delta.x;
	player->pos.y += player->delta.y;
	if (hit_wall(*player, map, text_size))
		player->pos.y -= player->delta.y;
}

void	key_press_move_down(t_player *player, int text_size, t_map map)
{
	player->pos.x -= player->delta.x;
	if (hit_wall(*player, map, text_size))
		player->pos.x += player->delta.x;
	player->pos.y -= player->delta.y;
	if (hit_wall(*player, map, text_size))
		player->pos.y += player->delta.y;
}
