/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 13:27:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_texture(t_error *error)
{
	if (error->texture != 0)
		ft_putstr_fd("MLX:\n", 2);
	if (error->texture & ERRN_01)
		ft_putstr_fd(ERRN_TEXTURE_STR_01, 2);
	if (error->texture & TEXTURE_ERROR_WITH_ARG_MASK)
		error_print_texture_known(error);
}
