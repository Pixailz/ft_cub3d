/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/13 20:40:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	key_press_move_left(t_main *config)
{
	config->player.angle -= 90 * DR;
	adjust_delta(&config->player);
	config->player.pos.x += config->player.delta.x;
	config->player.pos.y += config->player.delta.y;
	config->player.angle += 90 * DR;
	adjust_delta(&config->player);
}

void	key_press_move_right(t_main *config)
{
	config->player.angle += 90 * DR;
	adjust_delta(&config->player);
	config->player.pos.x += config->player.delta.x;
	config->player.pos.y += config->player.delta.y;
	config->player.angle -= 90 * DR;
	adjust_delta(&config->player);
}

void	key_press_move_up(t_main *config)
{
	config->player.pos.x += config->player.delta.x;
	config->player.pos.y += config->player.delta.y;
}

void	key_press_move_down(t_main *config)
{
	config->player.pos.x -= config->player.delta.x;
	config->player.pos.y -= config->player.delta.y;
}
