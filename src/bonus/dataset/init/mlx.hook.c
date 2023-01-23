/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 03:34:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	is_movement_key(int key_code)
{
	if (key_code == KEY_A || key_code == KEY_D || key_code == KEY_W || \
		key_code == KEY_S || key_code == KEY_LEFT || key_code == KEY_RIGHT)
		return (TRUE);
	return (FALSE);
}

void	set_movement(t_move *movement, int key_code, t_bool value)
{
	if (key_code == KEY_A)
		movement->left = value;
	else if (key_code == KEY_D)
		movement->rigth = value;
	else if (key_code == KEY_W)
		movement->up = value;
	else if (key_code == KEY_S)
		movement->down = value;
}

int	key_press(int key_code, t_main *config)
{
	debug_print(RENDER_KEY_PRESS, (void *)&key_code);
	if (is_movement_key(key_code))
		set_movement(&config->player.movement, key_code, TRUE);
	return (0);
}

int	key_release(int key_code, t_main *config)
{
	if (is_movement_key(key_code))
		set_movement(&config->player.movement, key_code, FALSE);
	if (key_code == KEY_ESC)
		return (end_hook(&config->mlx));
	return (0);
}

void	init_mlx_hook(t_main *config)
{
	t_mlx		*mlx;
	long int	mouse_mask;

	mlx = &config->mlx;
	config->cursor = 0;
	mlx_hook(mlx->win, 33, (1L << 17), end_hook, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_press, config);
	mlx_hook(mlx->win, 3, (1L << 1), key_release, config);
	mouse_mask = (1L << 6) | (1L << 2) | (1L << 3);
	mlx_hook(mlx->win, 6, mouse_mask, ft_get_axis, config);
	mlx_hook(mlx->win, 8, 1L << 5, ft_not_in_axis, config);
	mlx_do_key_autorepeaton(mlx->ptr);
	return ;
}
