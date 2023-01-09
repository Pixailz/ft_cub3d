/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:12:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 21:22:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_3d_map(t_main *config)
{
	int	counter;

	counter = 0;
	while (config->parsing.map[counter])
	{
		ft_printf_fd(1, "[%s]\n", config->parsing.map[counter]);
		counter++;
	}
}

int	draw_3d(t_main *config)
{
	draw_3d_map(config);
	return (0);
}
