/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 17:52:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_error(t_error *error)
{
	free(error);
	error = FT_NULL;
}

/* mode = 0		init and return pointeur to error struct
 * mode = 1		free error struct
 */
t_error	*get_error(int mode)
{
	static t_error	error = {0};

	if (mode == 0)
		return (&error);
	else if (mode == 1)
		free_error(get_error(0));
	return (FT_NULL);
}

/* mode = 0		malloc
 * mode = 1		args
 * mode = 2		texture
 */
t_return_value	set_error(unsigned char mode, t_return_value return_value)
{
	t_error	*error;

	error = get_error(0);
	if (mode == 0)
		error->malloc |= return_value;
	else if (mode == 1)
		error->args |= return_value;
	else if (mode == 2)
		error->texture |= return_value;
	return (return_value);
}

t_bool	have_error(int mode)
{
	t_error			*error;
	t_return_value	result;

	error = get_error(0);
	result = 0;
	if (mode == 0)
	{
		result |= error->malloc;
		result |= error->args;
		result |= error->texture;
	}
	else if (mode == 1)
		result |= error->malloc;
	else if (mode == 2)
		result |= error->args;
	else if (mode == 3)
		result |= error->texture;
	return (result);
}
