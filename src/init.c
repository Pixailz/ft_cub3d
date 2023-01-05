/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:06:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:44:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_parsing_entry(t_parse *parsing)
{
	parsing->map_fd = -1;
	parsing->north_file_path = FT_NULL;
	parsing->south_file_path = FT_NULL;
	parsing->west_file_path = FT_NULL;
	parsing->east_file_path = FT_NULL;
	parsing->ceiling[0] = -1;
	parsing->ceiling[1] = -1;
	parsing->ceiling[2] = -1;
	parsing->floor[0] = -1;
	parsing->floor[1] = -1;
	parsing->floor[2] = -1;
}

void	init_config_entry(t_main *config)
{
	config->ceiling[0] = -1;
	config->ceiling[1] = -1;
	config->ceiling[2] = -1;
	config->floor[0] = -1;
	config->floor[1] = -1;
	config->floor[2] = -1;
	config->path_to_north_file = FT_NULL;
	config->path_to_south_file = FT_NULL;
	config->path_to_west_file = FT_NULL;
	config->path_to_east_file = FT_NULL;
	config->map = FT_NULL;
}

void	init_entry(t_parse *parsing, t_main *config)
{
	init_parsing_entry(parsing);
	init_config_entry(config);
}
