/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 01:37:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	error_print_texture(t_error err)
{
	if (err.texture != 0)
		ft_put_padded_str(2, 1, "MLX:");
	if (err.texture & ERRN_01)
		ft_put_padded_str(2, 2, ERRN_TEXTURE_STR_01);
	if (err.texture & ERRN_04)
		ft_put_padded_str(2, 2, ERRN_TEXTURE_STR_02);
	if (err.texture & ERRN_MASK_TEXTURE_ARG)
		error_print_texture_known(err);
}
