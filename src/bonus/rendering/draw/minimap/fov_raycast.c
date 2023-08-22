/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:09:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/27 01:33:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	init_raycast_fov(t_ray *ray_fov, t_player *player, float angle, t_main *config)
{
	ray_fov->text_size = config->mini.max_text_size;
	ray_fov->bit_prec = get_bit_prec(config->mini.max_text_size);
	ray_fov->angle = angle - (DR * (FOV / 2));
	ray_fov->nbr = 0;
	ray_fov->nbr_ray = config->mini.circle.radius * 2;
	player->angle = angle;
	player->pos.x = config->player.pos.x / config->ray.text_size * \
													config->mini.max_text_size;
	player->pos.y = config->player.pos.y / config->ray.text_size * \
													config->mini.max_text_size;
}

void	raycast_fov(t_main *config, t_player player, t_ray *ray_fov)
{
	double		dist;

	ray_fov->hit = 0;
	if (ray_fov->angle < 0)
		ray_fov->angle += PI2;
	if (ray_fov->angle > PI2)
		ray_fov->angle -= PI2;
	ray_fov->a_tan = get_a_tan(ray_fov->angle);
	ray_fov->n_tan = get_n_tan(ray_fov->angle);
	fov_cast_ray_horizontal(ray_fov, player, config->parse.map);
	fov_cast_ray_vertical(ray_fov, player, config->parse.map);
	dist = get_dist(player.pos, ray_fov->pos);
	if (ray_fov->dist > dist)
	{
		ray_fov->dist = dist;
		ray_fov->save.x = ray_fov->pos.x;
		ray_fov->save.y = ray_fov->pos.y;
	}
}

void	raycast_fov_entry(t_main *config, float angle)
{
	t_ray		ray_fov;
	t_player	player;
	float		to_add;

	init_raycast_fov(&ray_fov, &player, angle, config);
	to_add = DR / (config->mini.circle.radius * 2 / FOV);
	while (ray_fov.nbr < ray_fov.nbr_ray)
	{
		raycast_fov(config, player, &ray_fov);
		raycast_fov_draw(config, player, ray_fov);
		ray_fov.angle += to_add;
		ray_fov.nbr++;
		if (ray_fov.nbr > config->mini.circle.radius * 2)
			break ;
	}
	raycast_fov_draw_line(config, player, ray_fov);
}
