/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:36:59 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 00:11:06 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_rendering(t_main *config)
{
	init_mlx(&config->mlx);
}

void	start_rendering(t_main *config)
{
	init_rendering(config);
}
