/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:03:19 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:03:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	debug_print_splitted(char **splitted)
{
	int	counter;

	counter = 0;
	while (splitted[counter])
	{
		ft_printf_fd(DEBUG_FD, \
			"splitted [%d]\t{%s}\n", counter, splitted[counter]);
		counter++;
	}
}

void	debug_print_surrounded(char **splitted)
{
	int	counter;

	counter = 0;
	while (splitted[counter])
	{
		ft_printf_fd(DEBUG_FD, \
			"surrounded[%d]\t{%s}\n", counter, splitted[counter]);
		counter++;
	}
}

void	debug_print_map_size(t_map *map)
{
	ft_printf_fd(DEBUG_FD, "map_size x:%d,y%d\n", map->size.x, map->size.y);
}

void	debug_print_parse(int mode, void *ptr)
{
	if (mode == PARSE_RETURN_VALUE)
		ft_printf_fd(DEBUG_FD, "return_value=[%d]\n", *((int *)ptr));
	else if (mode == PARSE_LINE)
		ft_printf_fd(DEBUG_FD, "line [%s]\n", (char *)ptr);
	else if (mode == PARSE_EMPTY_LINE)
		ft_printf_fd(DEBUG_FD, "empty_line\n");
	else if (mode == PARSE_PARAMS_DONE)
		ft_printf_fd(DEBUG_FD, "params_done\n");
	else if (mode == PARSE_GET_MAP)
		ft_printf_fd(DEBUG_FD, "left param_done [%s]\n", (char *)ptr);
	else if (mode == PARSE_GET_MAP_SPLITTED)
		debug_print_splitted((char **)ptr);
	else if (mode == PARSE_GET_MAP_SURROUDED)
		debug_print_surrounded((char **)ptr);
	else if (mode == PARSE_MAP_SIZE)
		debug_print_map_size((t_map *)ptr);
}
