/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 06:09:36 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 07:47:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	raycast_fov_draw_line(t_main *config, t_player player, t_ray ray_fov)
{
	t_line	line;

	line.begin.x = config->mini.circle.center.x;
	line.begin.y = config->mini.circle.center.y;
	line.end.x = config->mini.circle.center.x - \
		(int)(player.pos.x - ray_fov.save.x);
	line.end.y = config->mini.circle.center.y - \
		(int)(player.pos.y - ray_fov.save.y);
	line.color = PLAYER_ANGLE_COLOR;
	put_line_in_circle(&config->mlx.textures.scene, line, config->mini.circle);
}

void	raycast_fov_draw_hit(t_main *config, t_player player, t_ray ray_fov)
{
	t_i_pos	pos;

	pos.x = config->mini.circle.center.x - \
		(int)(player.pos.x - ray_fov.save.x);
	pos.y = config->mini.circle.center.y - \
		(int)(player.pos.y - ray_fov.save.y);
	ft_put_pixel_in_circle(pos, &config->mlx.textures.scene, 0xff0000, \
														config->mini.circle);
}

void	raycast_fov_draw(t_main *config, t_player player, t_ray ray_fov)
{
	if (!ray_fov.nbr)
		raycast_fov_draw_line(config, player, ray_fov);
	else
		raycast_fov_draw_hit(config, player, ray_fov);
}
