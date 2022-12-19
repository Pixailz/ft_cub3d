/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/19 14:51:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int			return_value;
	t_config	main;

	if (argc != 2)
		return (ft_printf_fd(2, "Error: program take one arguments.\n"));
	return_value = parse(argv[1], &main);
	if (return_value)
		return (parsing_error(return_value));
	free_entry(&main);
	return (0);
}
