/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:56:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_clean_value(t_parse *parsing, t_main *config)
{
	config->floor[0] = parsing->floor[0];
	config->floor[1] = parsing->floor[1];
	config->floor[2] = parsing->floor[2];
	config->ceiling[0] = parsing->ceiling[0];
	config->ceiling[1] = parsing->ceiling[1];
	config->ceiling[2] = parsing->ceiling[2];
	config->path_to_north_file = ft_strdup(parsing->north_file_path);
	config->path_to_north_file = ft_strdup(parsing->south_file_path);
	config->path_to_north_file = ft_strdup(parsing->west_file_path);
	config->path_to_north_file = ft_strdup(parsing->east_file_path);
	config->map = parsing->map;
}

int	main(int argc, char **argv)
{
	t_return_value	return_value;
	t_parse			parsing;
	t_main			config;

	if (argc != 2)
		return (ft_printf_fd(2, "Error: program take one arguments.\n"));
	init_entry(&parsing, &config);
	return_value = parse_entry(argv[1], &parsing);
	debug_print(PARSE_RETURN_VALUE, (void *)&return_value);
	if (return_value != -1)
	{
		free_entry_parsing(&parsing);
		return (parsing_error(return_value));
	}
	get_clean_value(&parsing, &config);
	free_entry_parsing(&parsing);
	free_entry_config(&config);
	return (return_value);
}
