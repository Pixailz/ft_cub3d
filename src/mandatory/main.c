/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 17:15:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

int	main(int argc, char **argv)
{
	t_main			config;

	if (argc != 2)
		return (ft_printf_fd(2, "Error:\nprogram take one arguments.\n"));
	init_config(&config);
	if (parse_entry(&config.err, argv[1], &config.parsing))
		return (error_print(config.err, &config));
	start_rendering(&config);
	error_print(config.err, &config);
	return (have_error(config.err, 0));
}
