/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 21:37:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	key_press_ray(int key_pressed, t_mlx *mlx)
{
	debug_print(RENDER_KEY_PRESS, (void *)&key_pressed);
	if (key_pressed == KEY_ESC)
		end_hook(mlx);
	return (0);
}

void	init_mlx_hook_ray(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx_hook(mlx->win_ray, 33, (1L << 17), end_hook, mlx);
	mlx_hook(mlx->win_ray, 2, (1L << 0), key_press_ray, mlx);
	mlx_do_key_autorepeaton(mlx->ptr);
	return ;
}
