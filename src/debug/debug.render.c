/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:24:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 00:41:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_print_screen_size(void *ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ptr;
	ft_printf_fd(DEBUG_FD, "screen_size{x=%d,y=%d}", mlx->screen_x, \
		mlx->screen_y);
}

void	debug_print_key(int key_code)
{
	ft_printf_fd(DEBUG_FD, "key_press [0x%x]\t", key_code);
	if (key_code == KEY_ESC)
		ft_putstr_fd("(ESC)", DEBUG_FD);
	else if (key_code == KEY_A)
		ft_putstr_fd("(A)", DEBUG_FD);
	else if (key_code == KEY_W)
		ft_putstr_fd("(W)", DEBUG_FD);
	else if (key_code == KEY_S)
		ft_putstr_fd("(S)", DEBUG_FD);
	else if (key_code == KEY_D)
		ft_putstr_fd("(D)", DEBUG_FD);
	else if (key_code == KEY_RIGHT)
		ft_putstr_fd("(RIGHT)", DEBUG_FD);
	else if (key_code == KEY_LEFT)
		ft_putstr_fd("(LEFT)", DEBUG_FD);
	else
		ft_putstr_fd("( ??? )", DEBUG_FD);
}

void	debug_print_render(int mode, void *ptr)
{
	if (mode == RENDER_SCREEN_SIZE)
		debug_print_screen_size(ptr);
	if (mode == RENDER_KEY_PRESS || mode == RENDER_KEY_RELEASE)
		debug_print_key(*(int *)ptr);
}
