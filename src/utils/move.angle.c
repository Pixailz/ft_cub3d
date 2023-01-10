/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 16:13:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	key_press_move_angle_left(t_main *config)
{
	config->player.angle -= DR * 30;
	dprintf(DEBUG_FD, "player.angle[%.2f]\n", config->player.angle);
	draw_ray(config);
	return ;
}

void	key_press_move_angle_right(t_main *config)
{
	config->player.angle += DR * 30;
	dprintf(DEBUG_FD, "player.angle[%.2f]\n", config->player.angle);
	draw_ray(config);
	return ;
}
