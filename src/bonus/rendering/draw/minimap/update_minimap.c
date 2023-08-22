/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 05:02:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 06:08:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	update_mini_map_vars(t_main *config, t_minimap *mini)
{
	mini->ppos.x = config->player.pos.x / config->ray.text_size;
	mini->ppos.y = config->player.pos.y / config->ray.text_size;
	mini->ppos_scaled.x = (int)(\
		(config->player.pos.x / config->ray.text_size) * mini->max_text_size) % \
		mini->max_text_size;
	mini->ppos_scaled.y = (int)(\
		(config->player.pos.y / config->ray.text_size) * mini->max_text_size) % \
		mini->max_text_size;
	mini->id.x = mini->ppos.x;
	mini->id.y = mini->ppos.y;
}

void	update_mini_circle(t_bool zoomed, t_circle *circle)
{
	if (zoomed)
	{
		circle->radius = MINI_EXPANDED_CIRCLE_RADIUS;
		circle->center.x = MINI_EXPANDED_CENTER_X;
		circle->center.y = MINI_EXPANDED_CENTER_Y;
	}
	else
	{
		circle->radius = MINI_CIRCLE_RADIUS;
		circle->center.x = MINI_CENTER_X;
		circle->center.y = MINI_CENTER_Y;
	}
	circle->color = MINI_EDGE_COLOR;
}

void	update_mini_map(t_main *config, t_minimap *mini)
{
	update_mini_circle(mini->zoomed, &mini->circle);
	update_mini_map_vars(config, mini);
}
