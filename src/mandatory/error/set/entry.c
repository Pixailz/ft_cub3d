/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:14 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 17:36:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

/* mode = 0		malloc
 * mode = 1		params
 * mode = 2		params_args
 * mode = 3		texture
 * mode = 4		texture_args
 */
t_r_value	set_error(t_error *err, unsigned char mode, t_r_value return_value)
{
	if (mode == 0)
		err->malloc |= return_value;
	else if (mode == 1)
		err->params |= return_value;
	else if (mode == 2)
		err->params_args |= return_value;
	else if (mode == 3)
		err->texture |= return_value;
	else if (mode == 4)
		err->texture_args |= return_value;
	return (return_value);
}

t_r_value	set_error_known_params(t_error *err, t_r_value err_no, int type)
{
	err->params |= err_no;
	if (err_no & ERRN_06)
		set_error_already_provided(type, &err->params_args);
	else if (err_no & ERRN_07)
		set_error_wrong_sep(type, &err->params_args);
	else if (err_no & ERRN_08)
		set_error_have_empty(type, &err->params_args);
	else if (err_no & ERRN_09)
		set_error_wrong_path(type, &err->params_args);
	else if (err_no & ERRN_10)
		set_error_wrong_color(err_no, type, &err->params_args);
	else if (err_no & ERRN_11)
		set_error_wrong_color(err_no, type, &err->params_args);
	else if (err_no & ERRN_12)
		set_error_wrong_color(err_no, type, &err->params_args);
	return (type);
}

t_r_value	set_error_known_texture(t_error *err, t_r_value err_no, int type)
{
	err->texture |= err_no;
	if (err_no & ERRN_02)
		set_error_mlx_window(type, &err->texture_args);
	else if (err_no & ERRN_03)
		set_error_mlx_texture(type, &err->texture_args);
	return (err_no);
}

/* mode == 0 -> params
 * mode == 1 -> texture
 */
t_r_value	set_error_known(t_error *err, int mode, t_r_value err_no, int type)
{
	if (mode == 0)
		set_error_known_params(err, err_no, type);
	else if (mode == 1)
		set_error_known_texture(err, err_no, type);
	return (err_no);
}
