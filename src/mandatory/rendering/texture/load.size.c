/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:15:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 18:52:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	get_highest_size(t_i_pos *highest, t_mlx_texture text)
{
	if (highest->x < text.len.x)
		highest->x = text.len.x;
	if (highest->y < text.len.y)
		highest->y = text.len.y;
}

unsigned char	get_bit_prec(int highest)
{
	unsigned char	counter;

	if (highest <= 0)
		return (0);
	counter = 0;
	while (highest - (1 << counter) > 0)
		counter++;
	return (counter);
}

void	get_raycast_size(t_main *config)
{
	t_i_pos			highest;
	t_mlx_textures	textures;

	textures = config->mlx.textures;
	highest.x = textures.raycast_wall.len.x;
	highest.y = textures.raycast_wall.len.y;
	if (highest.x < textures.raycast_void.len.x)
		highest.x = textures.raycast_void.len.x;
	if (highest.y < textures.raycast_void.len.y)
		highest.y = textures.raycast_void.len.y;
	if (highest.x > highest.y)
		config->ray.raycast_cell_size = highest.x;
	else
		config->ray.raycast_cell_size = highest.y;
	if (textures.raycast_player.len.x > textures.raycast_player.len.y)
		config->ray.raycast_player_size = textures.raycast_player.len.x;
	else
		config->ray.raycast_player_size = textures.raycast_player.len.y;
}

void	get_textures_size(t_main *config)
{
	t_mlx_textures	textures;
	t_i_pos			highest;

	textures = config->mlx.textures;
	highest.x = textures.north.len.x;
	highest.y = textures.north.len.y;
	get_highest_size(&highest, textures.south);
	get_highest_size(&highest, textures.west);
	get_highest_size(&highest, textures.east);
	if (RAY_ENABLE)
		get_raycast_size(config);
	if (highest.x < highest.y)
		config->ray.text_size = highest.y;
	else
		config->ray.text_size = highest.x;
	config->ray.bit_prec = get_bit_prec(config->ray.text_size);
}
