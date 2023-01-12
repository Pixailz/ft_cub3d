/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_mlx(t_r_value return_value)
{
	ft_putstr_fd("MLX: ", 2);
	if (return_value & ERRN_02)
		ft_putstr_fd(ERRN_MALLOC_STR_02, 2);
	if (return_value & ERRN_03)
		ft_putstr_fd(ERRN_MALLOC_STR_03, 2);
	if (return_value & ERRN_04)
		ft_putstr_fd(ERRN_MALLOC_STR_04, 2);
	if (return_value & ERRN_05)
		ft_putstr_fd(ERRN_MALLOC_STR_05, 2);
	if (return_value & ERRN_06)
		ft_putstr_fd(ERRN_MALLOC_STR_06, 2);
	if (return_value & ERRN_07)
		ft_putstr_fd(ERRN_MALLOC_STR_07, 2);
	if (return_value & ERRN_08)
		ft_putstr_fd(ERRN_MALLOC_STR_08, 2);
	return ;
}
