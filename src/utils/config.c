/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 19:38:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_config(t_main *config)
{
	init_parsing(&config->parsing);
	init_player(&config->player);
	init_error(&config->err);
}

void	free_config(t_main *config)
{
	free_parsing(&config->parsing);
	init_player(&config->player);
	if (DEBUG)
		close(DEBUG_FD);
}
