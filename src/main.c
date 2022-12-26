/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/24 12:56:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int			return_value;
	t_parse		main;

	if (argc != 2)
		return (ft_printf_fd(2, "Error: program take one arguments.\n"));
	init_entry(&main);
	return_value = parse_entry(argv[1], &main);
	debug_print(PARSE_RETURN_VALUE, (int *)&return_value);
	if (return_value && return_value != -1)
		return (parsing_error(return_value));
	free_entry(&main);
	return (return_value);
}
