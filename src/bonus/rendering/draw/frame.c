/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:32:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 12:47:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	do_moving(t_main *config)
{
	if (config->player.movement.left == TRUE)
		key_press_move_left(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.right == TRUE)
		key_press_move_right(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.up == TRUE)
		key_press_move_up(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.down == TRUE)
		key_press_move_down(&config->player, config->ray.text_size, \
															config->parse.map);
	if (config->player.movement.left_angle == TRUE)
		key_press_move_angle_left(&config->player, config->ray.text_size);
	if (config->player.movement.right_angle == TRUE)
		key_press_move_angle_right(&config->player, config->ray.text_size);
}

void	put_background(t_int4 floor, t_int4 ceiling, t_mlx_texture *scene)
{
	t_i_pos	pos;

	pos.y = 0;
	while (pos.y <= scene->len.y / 2)
	{
		pos.x = 0;
		while (pos.x <= scene->len.x)
		{
			ft_put_pixel(pos.x, pos.y, scene, ceiling);
			pos.x++;
		}
		pos.y++;
	}
	while (pos.y <= scene->len.y)
	{
		pos.x = 0;
		while (pos.x <= scene->len.x)
		{
			ft_put_pixel(pos.x, pos.y, scene, floor);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_background(t_main *config)
{
	int	x_x;
	int	y_y;

	x_x = config->player.pos.x / config->ray.text_size;
	y_y = config->player.pos.y / config->ray.text_size;
	if (x_x >= MAX_DOF && y_y >= MAX_DOF && \
								x_x < config->parse.map.size.x + MAX_DOF && \
								y_y < config->parse.map.size.y + MAX_DOF)
	{
		put_background(config->parse.textures.floor, \
			config->parse.textures.ceiling, &config->mlx.textures.scene);
	}
}

void	frame_id_process(t_main *config, int *frame_id)
{
	int	elapsed;

	(*frame_id)++;
	elapsed = *frame_id * config->mlx.frame_time;
	if (elapsed >= 1)
	{
		switch_textures(&config->mlx.textures);
		*frame_id = 0;
	}
}


int	draw_frame(t_main *config)
{
	static int	frame_id = 0;

	ft_memset(config->mlx.textures.scene.buff, 0, \
				config->mlx.screen.y * config->mlx.textures.scene.size_line);
	do_moving(config);
	draw_background(config);
	cast_ray_entry(config);
	if (config->player.movement.reading_map)
		draw_minimap(config);
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
		config->mlx.textures.scene.ptr, 0, 0);
	//usleep(ONE_SEC / 10000);
	frame_id_process(config, &frame_id);
	return (0);
}
