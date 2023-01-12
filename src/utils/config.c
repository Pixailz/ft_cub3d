/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:18:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_config(t_main *config)
{
	init_parsing(&config->parsing);
	init_player(config->player);
}

void	free_config(t_main *config)
{
	free_parsing(&config->parsing);
	init_player(config->player);
	if (DEBUG)
		close(DEBUG_FD);
}
