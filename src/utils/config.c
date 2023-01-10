/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 15:17:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_config(t_main *config)
{
	init_parsing(&config->parsing);
	config->player.pos.x = -1;
	config->player.pos.y = -1;
	config->player.angle = 0;
}

void	free_config(t_main *config)
{
	free_parsing(&config->parsing);
	if (DEBUG)
		close(DEBUG_FD);
}
