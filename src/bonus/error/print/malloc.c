/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 01:37:06 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	error_print_malloc(t_r_value return_value)
{
	ft_put_padded_str(2, 1, "Malloc:");
	if (return_value & ERRN_01)
		ft_put_padded_str(2, 2, ERRN_MALLOC_STR_01);
	if (return_value & ERRN_02)
		ft_put_padded_str(2, 2, ERRN_MALLOC_STR_02);
	if (return_value & ERRN_03)
		ft_put_padded_str(2, 2, ERRN_MALLOC_STR_03);
	if (return_value & ERRN_04)
		ft_put_padded_str(2, 2, ERRN_MALLOC_STR_04);
}
