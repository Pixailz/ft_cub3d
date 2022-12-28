/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/26 10:56:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	parsing_error_args(int return_code)
{
	if (return_code == 1)
		ft_printf_fd(2, "The file name is too short");
	else if (return_code == 2)
		ft_printf_fd(2, "Wrong file extension");
	else if (return_code == 3)
		ft_printf_fd(2, "%s", strerror(errno));
	else if (return_code == 4)
		ft_printf_fd(2, "Empty file");
}

void	parsing_error_params(int return_code)
{
	if (return_code == 5)
		ft_printf_fd(2, "Wrong line begining");
	else if (return_code == 6)
		ft_printf_fd(2, "line already provided");
	else if (return_code == 7)
		ft_printf_fd(2, \
			"Specifier and informations are not separated by a SPACE");
	else if (return_code == 8)
		ft_printf_fd(2, "Specifier don't have informations");
	else if (return_code == 9)
		ft_printf_fd(2, "Wrong format for informations on color specifier");
	else if (return_code == 10)
		ft_printf_fd(2, "Non numeric on color specifier");
	else if (return_code == 11)
		ft_printf_fd(2, "Wrong number for colors");
}

void	parsing_error_texture_type(int line_type)
{
	ft_printf_fd(2, "Texture");
	if (line_type == NO)
		ft_printf_fd(2, "(NO)");
	else if (line_type == SO)
		ft_printf_fd(2, "(SO)");
	else if (line_type == WE)
		ft_printf_fd(2, "(WE)");
	else if (line_type == EA)
		ft_printf_fd(2, "(EA)");
	ft_printf_fd(2, ": %s", strerror(errno));
}

void	parsing_error_map(int return_code)
{
	if (return_code == 12)
		ft_printf_fd(2, "Wrong map format");
	else if (return_code == 13)
		ft_printf_fd(2, "More than one player in map");
	else if (return_code == 14)
		ft_printf_fd(2, "Wrong char in map");
	else if (return_code == 15)
		ft_printf_fd(2, "Bad Alloc");
	else if (return_code == 16)
		ft_printf_fd(2, "No player in map");
	else if (return_code == 17)
		ft_printf_fd(2, "No map in file");
}

int	parsing_error(int return_code)
{
	ft_printf_fd(2, "Error: ");
	if (return_code >= 1 && return_code <= 4)
		parsing_error_args(return_code);
	else if (return_code >= 5 && return_code <= 11)
		parsing_error_params(return_code);
	else if (return_code >= 12 && return_code <= 17)
		parsing_error_map(return_code);
	else if ((return_code & 0xff) == 0xff)
		parsing_error_texture_type(return_code >> 8);
	ft_printf_fd(2, "\n");
	return (return_code);
}
