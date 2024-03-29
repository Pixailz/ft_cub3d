/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:24:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 06:10:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	debug_print_screen_size(void *ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ptr;
	ft_printf_fd(DEBUG_FD, "screen_size 3D {x=%d,y=%d}\n", mlx->screen.x, \
		mlx->screen.y);
}

void	debug_print_player_stat(t_player *player)
{
	if (VERBOSE >= 2)
	{
		dprintf(DEBUG_FD, "player.pos.x\t(x:%.2f,y:%.2f)\n", \
			player->pos.x, player->pos.y);
		dprintf(DEBUG_FD, "player angle\t(x:%.2f.y:%.2f)\n", \
			player->angle.x, player->angle.y);
		dprintf(DEBUG_FD, "player.delta.x\t(x:%.2f.y:%.2f)\n", \
			player->delta.x, player->delta.y);
	}
}

void	debug_print_render(int mode, void *ptr)
{
	if (mode == RENDER_SCREEN_SIZE)
		debug_print_screen_size(ptr);
	if (mode == RENDER_KEY_PRESS || mode == RENDER_KEY_RELEASE)
		debug_print_key(*(int *)ptr);
	if (mode == RENDER_PLAYER)
		debug_print_player_stat((t_player *)ptr);
	if (mode == RENDER_LINE)
		debug_print_line_pos((t_line *)ptr);
}
