/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 20:46:59 by brda-sil         ###   ########.fr       */
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
