/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:14 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 17:34:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* mode = 0		malloc
 * mode = 1		params
 * mode = 2		params_args
 * mode = 3		texture
 * mode = 4		texture_args
 */
t_r_value	set_error(unsigned char mode, t_r_value return_value)
{
	t_error	*error;

	error = get_error();
	if (mode == 0)
		error->malloc |= return_value;
	else if (mode == 1)
		error->params |= return_value;
	else if (mode == 2)
		error->params_args |= return_value;
	else if (mode == 3)
		error->texture |= return_value;
	else if (mode == 4)
		error->texture_args |= return_value;
	return (return_value);
}

t_r_value	set_error_known_params_args(t_r_value err_no, int type)
{
	t_error	*error;

	error = get_error();
	error->params |= err_no;
	if (err_no & ERRN_06)
		set_error_already_provided(type, &error->params_args);
	else if (err_no & ERRN_07)
		set_error_wrong_sep(type, &error->params_args);
	else if (err_no & ERRN_08)
		set_error_have_empty(type, &error->params_args);
	else if (err_no & ERRN_09)
		set_error_wrong_path(type, &error->params_args);
	else if (err_no & ERRN_10)
		set_error_wrong_color(err_no, type, &error->params_args);
	else if (err_no & ERRN_11)
		set_error_wrong_color(err_no, type, &error->params_args);
	else if (err_no & ERRN_12)
		set_error_wrong_color(err_no, type, &error->params_args);
	return (type);
}

t_r_value	set_error_known_texture_args(t_r_value err_no, int type)
{
	t_error	*error;

	error = get_error();
	error->texture |= err_no;
	if (err_no & ERRN_02)
		set_error_mlx_window(type, &error->texture_args);
	else if (err_no & ERRN_03)
		set_error_mlx_texture(type, &error->texture_args);
	return (err_no);
}

/* mode == 0 -> params
 * mode == 1 -> texture
 */
t_r_value	set_error_known(int mode, t_r_value err_no, int type)
{
	if (mode == 0)
		set_error_known_params_args(err_no, type);
	else if (mode == 1)
		set_error_known_texture_args(err_no, type);
	return (err_no);
}
