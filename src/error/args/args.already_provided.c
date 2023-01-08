/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.already_provided.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 19:47:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_args_already_provided(t_return_value return_value)
{
	ft_putstr_fd(ERRN_ARGS_STR_06, 2);
	if (return_value & ERRN_01)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_02)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_03)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_04)
		ft_putstr_fd(" (EA)", 2);
	if (return_value & ERRN_05)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_06)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	set_error_already_provided(int line_type, t_return_value *return_value)
{
	if (line_type == NORTH)
		*return_value |= ERRN_01;
	if (line_type == SOUTH)
		*return_value |= ERRN_02;
	if (line_type == WEST)
		*return_value |= ERRN_03;
	if (line_type == EAST)
		*return_value |= ERRN_04;
	if (line_type == FLOOR)
		*return_value |= ERRN_05;
	if (line_type == CEIL)
		*return_value |= ERRN_06;
}
