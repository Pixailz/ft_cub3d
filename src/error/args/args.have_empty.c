/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.have_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 19:47:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_args_have_empty(t_return_value return_value)
{
	ft_putstr_fd(ERRN_ARGS_STR_08, 2);
	if (return_value & ERRN_13)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_14)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_15)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_16)
		ft_putstr_fd(" (EA)", 2);
	if (return_value & ERRN_17)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_18)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	set_error_have_empty(int line_type, t_return_value *return_value)
{
	if (line_type == NORTH)
		*return_value |= ERRN_13;
	if (line_type == SOUTH)
		*return_value |= ERRN_14;
	if (line_type == WEST)
		*return_value |= ERRN_15;
	if (line_type == EAST)
		*return_value |= ERRN_16;
	if (line_type == FLOOR)
		*return_value |= ERRN_17;
	if (line_type == CEIL)
		*return_value |= ERRN_18;
}
