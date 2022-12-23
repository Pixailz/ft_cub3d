/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 15:38:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

void	parsing_error_parameters(int return_code)
{
	if (return_code == 1)
		ft_printf_fd(2, "The file name is too short");
	else if (return_code == 2)
		ft_printf_fd(2, "Wrong file extension");
	else if (return_code == 3)
		ft_printf_fd(2, "%s", strerror(errno));
	else if (return_code == 4)
		ft_printf_fd(2, "Empty file");
	else if (return_code == 5)
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
	else if ((return_code & 0xff) == 0xff)
		parsing_error_texture_type(return_code >> 8);
}

int	parsing_error(int return_code)
{
	ft_printf_fd(2, "Error: ");
	parsing_error_parameters(return_code);
	ft_printf_fd(2, "\n");
	return (return_code);
}
