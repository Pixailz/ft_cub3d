/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:03:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	end_hook(t_mlx *mlx)
{
	mlx_loop_end(mlx->ptr);
	return (0);
}

t_bool	is_movement_key(int key_code)
{
	if (key_code == KEY_A || key_code == KEY_D || key_code == KEY_W || \
		key_code == KEY_S || key_code == KEY_LEFT || key_code == KEY_RIGHT)
		return (TRUE);
	return (FALSE);
}

t_bool	hit_wall(t_player player, t_map map, int text_size)
{
	if ((int)(player.pos.x/text_size) >= 0 && (int)(player.pos.y/text_size) >= 0)
		if ((int)(player.pos.x/text_size) < map.size.x && (int)(player.pos.y/text_size) < map.size.y)
			if (map.matrix[(int)(player.pos.y/text_size)][(int)(player.pos.x/text_size)] == WALL_CHAR)
				return (TRUE);
	return (FALSE);
}

void	move(int key_code, t_main *config)
{
	if (key_code == KEY_A)
	{
		key_press_move_left(&config->player, config->ray.text_size);
		if (hit_wall(config->player, config->parsing.map, config->ray.text_size))
			key_press_move_right(&config->player, config->ray.text_size);
	}
	else if (key_code == KEY_D)
	{
		key_press_move_right(&config->player, config->ray.text_size);
		if (hit_wall(config->player, config->parsing.map, config->ray.text_size))
		{
			key_press_move_left(&config->player, config->ray.text_size);
		}
	}
	else if (key_code == KEY_W)
	{
		key_press_move_up(&config->player);
		if (hit_wall(config->player, config->parsing.map, config->ray.text_size))
			key_press_move_down(&config->player);
	}
	else if (key_code == KEY_S)
	{
		key_press_move_down(&config->player);
		if (hit_wall(config->player, config->parsing.map, config->ray.text_size))
			key_press_move_up(&config->player);
	}
	draw_scene(config);
}

int	key_press(int key_code, t_main *config)
{
	debug_print(RENDER_KEY_PRESS, (void *)&key_code);
	if (is_movement_key(key_code))
		move(key_code, config);
	else if (key_code == KEY_ESC)
		return (end_hook(&config->mlx));
	return (0);
}

int	ft_get_axis(int x, int y, t_main *config)
{
	(void)y;
	if (config->cursor == 0)
	{
		config->cursor = x;
		return(0);
	}
	if (config->cursor - x > 0)
	{
		key_press_move_angle_left(&config->player, config->ray.text_size);
		config->cursor = x;
		draw_scene(config);
	}
	else if (config->cursor - x < 0)
	{
		key_press_move_angle_right(&config->player, config->ray.text_size);
		config->cursor = x;
		draw_scene(config);
	}
	return(1);
	
}

void	init_mlx_hook(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	config->cursor = 0;
	mlx_hook(mlx->win, 33, (1L << 17), end_hook, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_press, config);
	mlx_hook(mlx->win, 6, 1L << 6, ft_get_axis, config);
	mlx_do_key_autorepeaton(mlx->ptr);
	return ;
}
