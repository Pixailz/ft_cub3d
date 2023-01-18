/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:04:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	error_print_texture(t_error err)
{
	if (err.texture != 0)
		ft_putstr_fd("MLX:\n", 2);
	if (err.texture & ERRN_01)
		ft_putendl_fd(ERRN_TEXTURE_STR_01, 2);
	if (err.texture & ERRN_04)
		ft_putendl_fd(ERRN_TEXTURE_STR_04, 2);
	if (err.texture & ERRN_MASK_TEXTURE_ARG)
		error_print_texture_known(err);
}
