/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.animated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:56:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 11:46:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	load_texture_animated(t_mlx_a_text *text, t_file_l *file_l, int type, t_main *config)
{
	int			counter;
	t_file_l	*next;

	text->frame_nb = lstsize_file(file_l);
	text->frame_id = 0;
	text->frame = (t_mlx_texture *)ft_calloc(sizeof(t_mlx_texture), \
																text->frame_nb);
	if (!text->frame)
		return (set_error(&config->err, 0, ERRN_06));
	counter = text->frame_nb;
	while (counter--)
	{
		next = file_l->next;
		if (load_texture(&text->frame[counter], file_l->file.path, \
															config->mlx.ptr))
			return (set_error_known_texture(&config->err, ERRN_03, type));
		file_l = next;
	}
	text->current_frame = &text->frame[0];
	return (0);
}

int	get_frame_nb_max(t_mlx_textures text)
{
	int	max_size;

	max_size = text.north.frame_nb;
	if (max_size < text.south.frame_nb)
		max_size = text.south.frame_nb;
	if (max_size < text.west.frame_nb)
		max_size = text.west.frame_nb;
	if (max_size < text.east.frame_nb)
		max_size = text.east.frame_nb;
	return (max_size);
}

int	load_textures_animated(t_main *config)
{
	if (load_texture_animated(&config->mlx.textures.north, \
							config->parse.textures.north_file, NORTH, config))
		return (1);
	if (load_texture_animated(&config->mlx.textures.south, \
							config->parse.textures.south_file, SOUTH, config))
		return (1);
	if (load_texture_animated(&config->mlx.textures.west, \
							config->parse.textures.west_file, WEST, config))
		return (1);
	if (load_texture_animated(&config->mlx.textures.east, \
							config->parse.textures.east_file, EAST, config))
		return (1);
	config->mlx.textures.frame_nb_max = get_frame_nb_max(config->mlx.textures);
	return (0);
}
