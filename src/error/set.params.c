/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:14 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 16:25:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_error_already_provided(int type, t_r_value *return_value)
{
	if (type == NORTH)
		*return_value |= ERRN_01;
	if (type == SOUTH)
		*return_value |= ERRN_02;
	if (type == WEST)
		*return_value |= ERRN_03;
	if (type == EAST)
		*return_value |= ERRN_04;
	if (type == FLOOR)
		*return_value |= ERRN_05;
	if (type == CEIL)
		*return_value |= ERRN_06;
}

void	set_error_wrong_sep(int type, t_r_value *return_value)
{
	if (type == NORTH)
		*return_value |= ERRN_07;
	if (type == SOUTH)
		*return_value |= ERRN_08;
	if (type == WEST)
		*return_value |= ERRN_09;
	if (type == EAST)
		*return_value |= ERRN_10;
	if (type == FLOOR)
		*return_value |= ERRN_11;
	if (type == CEIL)
		*return_value |= ERRN_12;
}

void	set_error_have_empty(int type, t_r_value *return_value)
{
	if (type == NORTH)
		*return_value |= ERRN_13;
	if (type == SOUTH)
		*return_value |= ERRN_14;
	if (type == WEST)
		*return_value |= ERRN_15;
	if (type == EAST)
		*return_value |= ERRN_16;
	if (type == FLOOR)
		*return_value |= ERRN_17;
	if (type == CEIL)
		*return_value |= ERRN_18;
}

void	set_error_wrong_path(int type, t_r_value *return_value)
{
	if (type == NORTH)
		*return_value |= ERRN_19;
	if (type == SOUTH)
		*return_value |= ERRN_20;
	if (type == WEST)
		*return_value |= ERRN_21;
	if (type == EAST)
		*return_value |= ERRN_22;
}

void	set_error_wrong_color(t_r_value err_no, int type, t_r_value *param_args)
{
	if (err_no & ERRN_10)
	{
		if (type == FLOOR)
			*param_args |= ERRN_23;
		else if (type == CEIL)
			*param_args |= ERRN_24;
	}
	if (err_no & ERRN_11)
	{
		if (type == FLOOR)
			*param_args |= ERRN_25;
		else if (type == CEIL)
			*param_args |= ERRN_26;
	}
	if (err_no & ERRN_12)
	{
		if (type == FLOOR)
			*param_args |= ERRN_27;
		else if (type == CEIL)
			*param_args |= ERRN_28;
	}
}
