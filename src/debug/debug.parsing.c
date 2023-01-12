/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:03:19 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 19:29:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

void	debug_print_parse(int mode, void *ptr)
{
	if (mode == PARSE_RETURN_VALUE)
		ft_printf_fd(DEBUG_FD, "return_value=[%d]", *((int *)ptr));
	else if (mode == PARSE_LINE)
		ft_printf_fd(DEBUG_FD, "line [%s]", (char *)ptr);
	else if (mode == PARSE_EMPTY_LINE)
		ft_printf_fd(DEBUG_FD, "empty_line");
	else if (mode == PARSE_PARAMS_DONE)
		ft_printf_fd(DEBUG_FD, "params_done");
	else if (mode == PARSE_GET_MAP)
		ft_printf_fd(DEBUG_FD, "left param_done [%s]", (char *)ptr);
	else if (mode == PARSE_GET_MAP_SPLITTED)
		debug_print_splitted((char **)ptr);
	else if (mode == PARSE_GET_MAP_SURROUDED)
		debug_print_surrounded((char **)ptr);
}