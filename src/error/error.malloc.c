/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_malloc(t_r_value return_value)
{
	t_r_value	mlx_have_error;

	mlx_have_error = return_value & MLX_ERROR_MASK;
	if (return_value & ERRN_01)
	{
		ft_putstr_fd("Malloc: ", 2);
		ft_putstr_fd(ERRN_MALLOC_STR_01, 2);
	}
	if (mlx_have_error)
		error_print_mlx(return_value);
	ft_putchar_fd('\n', 2);
}
