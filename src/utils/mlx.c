/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 13:51:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_mlx_texture(t_mlx_texture *text)
{
	text->ptr = FT_NULL;
	text->buff = FT_NULL;
	text->bpp = -1;
	text->endian = -1;
	text->size_line = -1;
	text->len_x = -1;
	text->len_y = -1;
}

void	init_mlx_textures(t_mlx_textures *textures)
{
	init_mlx_texture(&textures->north);
	init_mlx_texture(&textures->south);
	init_mlx_texture(&textures->west);
	init_mlx_texture(&textures->east);
	init_mlx_texture(&textures->mini_wall);
	init_mlx_texture(&textures->mini_void);
	init_mlx_texture(&textures->mini_player);
}

t_r_value	init_mlx(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (set_error(0, ERRN_02));
	init_mlx_textures(&mlx->textures);
	mlx->screen_x = DEFAULT_SCREEN_X;
	mlx->screen_y = DEFAULT_SCREEN_Y;
	if (FULL_SCREEN)
		mlx_get_screen_size(mlx->ptr, &mlx->screen_x, &mlx->screen_y);
	debug_print(RENDER_SCREEN_SIZE, (void *)mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->screen_x, mlx->screen_y, \
															WINDOW_TITLE);
	if (!mlx->win)
		return (set_error(0, ERRN_03));
	init_mlx_hook(config);
	return (0);
}
