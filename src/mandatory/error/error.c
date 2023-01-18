/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:04:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

/* init error struct
 */
void	init_error(t_error *err)
{
	err->malloc = 0UL;
	err->params = 0UL;
	err->params_args = 0UL;
	err->texture = 0UL;
	err->texture_args = 0UL;
}

/* mode = 0		all
 * mode = 1		malloc
 * mode = 2		params
 * mode = 3		params_args
 * mode = 4		texture
 * mode = 5		texture_args
 */
t_bool	have_error(t_error err, int mode)
{
	t_r_value		result;

	result = 0;
	if (mode == 0)
	{
		result |= err.malloc;
		result |= err.params;
		result |= err.params_args;
		result |= err.texture;
		result |= err.texture_args;
	}
	else if (mode == 1)
		result |= err.malloc;
	else if (mode == 2)
		result |= err.params;
	else if (mode == 3)
		result |= err.params_args;
	else if (mode == 4)
		result |= err.texture;
	else if (mode == 5)
		result |= err.texture_args;
	return (result);
}
