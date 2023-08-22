/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:59:33 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 12:05:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	switch_texture(t_mlx_a_text *textures_a)
{
	if (textures_a->frame_id == textures_a->frame_nb - 1)
		textures_a->frame_id = 0;
	else
		textures_a->frame_id++;
	textures_a->current_frame = &textures_a->frame[textures_a->frame_id];
}

void	switch_textures(t_mlx_textures *textures)
{
	switch_texture(&textures->north);
	switch_texture(&textures->south);
	switch_texture(&textures->west);
	switch_texture(&textures->east);
}
