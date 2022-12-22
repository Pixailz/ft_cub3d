/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 07:16:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parsing_error(int return_code)
{
	if (return_code == 1)
		ft_printf_fd(2, "Error: The file name is too short\n");
	else if (return_code == 2)
		ft_printf_fd(2, "Error: Wrong file extension\n");
	else if (return_code == 3)
		ft_printf_fd(2, "Error: %s\n", strerror(errno));
	else if (return_code == 4)
		ft_printf_fd(2, "Error: Empty file\n");
	else if (return_code == 5)
		ft_printf_fd(2, "Error: Wrong line begining\n");
	else if (return_code == 6)
		ft_printf_fd(2, "Error: line already provided\n");
	return (return_code);
}
