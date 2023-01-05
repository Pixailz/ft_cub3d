/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:50:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:57:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_entry_config(t_main *config)
{
	ft_free_char_pointer(config->path_to_north_file);
	ft_free_char_pointer(config->path_to_south_file);
	ft_free_char_pointer(config->path_to_west_file);
	ft_free_char_pointer(config->path_to_east_file);
	if (config->map[0])
		ft_free_char_pp(config->map);
}
