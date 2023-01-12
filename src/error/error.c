/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:32:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* init error struct
 */
t_error	*get_error(void)
{
	static t_error	error = {0};

	return (&error);
}

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

/* mode = 0		all
 * mode = 1		malloc
 * mode = 2		params
 * mode = 3		params_args
 * mode = 4		texture
 * mode = 5		texture_args
 */
t_bool	have_error(int mode)
{
	t_error			*error;
	t_r_value		result;

	error = get_error();
	result = 0;
	if (mode == 0)
	{
		result |= error->malloc;
		result |= error->params;
		result |= error->params_args;
		result |= error->texture;
		result |= error->texture_args;
	}
	else if (mode == 1)
		result |= error->malloc;
	else if (mode == 2)
		result |= error->params;
	else if (mode == 3)
		result |= error->params_args;
	else if (mode == 4)
		result |= error->texture;
	else if (mode == 5)
		result |= error->texture_args;
	return (result);
}
