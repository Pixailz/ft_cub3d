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

void	get_lowest_size(t_i_pos *lowest, t_mlx_texture text)
{
	if (lowest->x > text.len.x)
		lowest->x = text.len.x;
	if (lowest->y > text.len.y)
		lowest->y = text.len.y;
}

unsigned char	get_bit_prec(int lowest)
{
	unsigned char	counter;

	if (lowest <= 0)
		return (0);
	counter = 0;
	while (lowest - (1 << counter) > 0)
		counter++;
	return (counter);
}

void	get_textures_size(t_main *config)
{
	t_mlx_textures	textures;
	t_i_pos			lowest;

	textures = config->mlx.textures;
	lowest.x = textures.north.len.x;
	lowest.y = textures.north.len.y;
	get_lowest_size(&lowest, textures.south);
	get_lowest_size(&lowest, textures.west);
	get_lowest_size(&lowest, textures.east);
	if (lowest.x > lowest.y)
		config->ray.text_size = lowest.y;
	else
		config->ray.text_size = lowest.x;
	config->ray.bit_prec = get_bit_prec(config->ray.text_size);
}
