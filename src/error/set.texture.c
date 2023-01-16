/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:14 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 18:02:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_r_value	set_error_mlx_window(t_param_type type, t_r_value *return_value)
{
	if (type == MAIN_WINDOW)
		*return_value |= ERRN_01;
	if (type == MAIN_WINDOW)
		*return_value |= ERRN_01;
	return (*return_value);
}

t_r_value	set_error_mlx_texture(t_param_type type, t_r_value *return_value)
{
	if (type == NORTH)
		*return_value |= ERRN_03;
	if (type == SOUTH)
		*return_value |= ERRN_04;
	if (type == WEST)
		*return_value |= ERRN_05;
	if (type == EAST)
		*return_value |= ERRN_06;
	if (type == MINI_VOID)
		*return_value |= ERRN_07;
	if (type == MINI_WALL)
		*return_value |= ERRN_08;
	if (type == MINI_PLAYER)
		*return_value |= ERRN_09;
	if (type == MINI_HIT)
		*return_value |= ERRN_10;
	return (*return_value);
}
