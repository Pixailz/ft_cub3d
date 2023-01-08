/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.wrong_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 19:46:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_args_wrong_path(t_return_value return_value)
{
	ft_printf_fd(2, "%s", strerror(errno));
	if (return_value & ERRN_19)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_20)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_21)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_22)
		ft_putstr_fd(" (EA)", 2);
	ft_putchar_fd('\n', 2);
}

void	set_error_wrong_path(int line_type, t_return_value *return_value)
{
	if (line_type == NORTH)
		*return_value |= ERRN_19;
	if (line_type == SOUTH)
		*return_value |= ERRN_20;
	if (line_type == WEST)
		*return_value |= ERRN_21;
	if (line_type == EAST)
		*return_value |= ERRN_22;
}
