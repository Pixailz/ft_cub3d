/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.wrong_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 19:28:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_args_wrong_sep(t_return_value return_value)
{
	ft_printf_fd(2, ERRN_ARGS_STR_07);
	if (return_value & ERRN_07)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_08)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_09)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_10)
		ft_putstr_fd(" (EA)", 2);
	if (return_value & ERRN_11)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_12)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	set_error_wrong_sep(int line_type, t_return_value *return_value)
{
	if (line_type == NORTH)
		*return_value |= ERRN_07;
	if (line_type == SOUTH)
		*return_value |= ERRN_08;
	if (line_type == WEST)
		*return_value |= ERRN_09;
	if (line_type == EAST)
		*return_value |= ERRN_10;
	if (line_type == FLOOR)
		*return_value |= ERRN_11;
	if (line_type == CEIL)
		*return_value |= ERRN_12;
}
