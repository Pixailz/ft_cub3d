/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 04:32:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	ft_get_axis(int x, int y, t_main *config)
{
	config->player.movement.left_angle = FALSE;
	config->player.movement.right_angle = FALSE;
	if (x < config->mlx.screen.x * 0.45)
	{
		config->player.movement.left_angle = TRUE;
		config->player.movement.r_speed = ((config->mlx.screen.x / 2 - x)) / \
												(config->mlx.screen.x * 0.45);
	}
	else if (x > config->mlx.screen.x * 0.55)
	{
		config->player.movement.right_angle = TRUE;
		config->player.movement.r_speed = (x - config->mlx.screen.x / 2) / \
												(config->mlx.screen.x * 0.45);
	}
	return (y);
}

int	ft_not_in_axis(t_main *config)
{
	config->player.movement.left_angle = FALSE;
	config->player.movement.right_angle = FALSE;
	return (0);
}
