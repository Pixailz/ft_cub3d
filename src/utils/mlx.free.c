/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 18:15:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_mlx_texture(void *mlx, t_mlx_texture *text)
{
	if (text->ptr)
		mlx_destroy_image(mlx, text->ptr);
}

void	free_mlx_textures(t_mlx *mlx)
{
	t_mlx_textures	*textures;

	textures = &mlx->textures;
	free_mlx_texture(mlx->ptr, &textures->north);
	free_mlx_texture(mlx->ptr, &textures->south);
	free_mlx_texture(mlx->ptr, &textures->west);
	free_mlx_texture(mlx->ptr, &textures->east);
	free_mlx_texture(mlx->ptr, &textures->mini_wall);
	free_mlx_texture(mlx->ptr, &textures->mini_void);
	free_mlx_texture(mlx->ptr, &textures->mini_player);
	free_mlx_texture(mlx->ptr, &textures->mini_hit);
	free_mlx_texture(mlx->ptr, &textures->scene);
}

void	free_mlx(t_mlx *mlx)
{
	free_mlx_textures(mlx);
	mlx_destroy_window(mlx->ptr, mlx->win);
	if (RAYCAST_ENABLE)
		mlx_destroy_window(mlx->ptr, mlx->win_raycasting);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	mlx->ptr = FT_NULL;
	mlx = FT_NULL;
}
