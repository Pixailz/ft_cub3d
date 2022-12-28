/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:06:13 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/28 07:40:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_file(t_parse *main)
{
	main->file = -1;
	main->north_file = -1;
	main->south_file = -1;
	main->west_file = -1;
	main->east_file = -1;
}

void	init_entry(t_parse *main)
{
	init_file(main);
	main->map = NULL;
	main->ceiling[0] = 0;
	main->ceiling[1] = 0;
	main->ceiling[2] = 0;
	main->floor[0] = 0;
	main->floor[1] = 0;
	main->floor[2] = 0;
}
