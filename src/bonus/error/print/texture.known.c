/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.known.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 04:03:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	error_print_texture_window(t_error err)
{
	ft_put_padded(2, 2);
	ft_putstr_fd(ERRN_TEXTURE_STR_02, 2);
	if (err.texture_args & ERRN_01)
		ft_putstr_fd(" (Main)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_texture_load(t_error err)
{
	ft_put_padded(2, 2);
	ft_putstr_fd(ERRN_TEXTURE_STR_03, 2);
	if (err.texture_args & ERRN_03)
		ft_putstr_fd(" (North)", 2);
	if (err.texture_args & ERRN_04)
		ft_putstr_fd(" (South)", 2);
	if (err.texture_args & ERRN_05)
		ft_putstr_fd(" (West)", 2);
	if (err.texture_args & ERRN_06)
		ft_putstr_fd(" (East)", 2);
	if (err.texture_args & ERRN_07)
		ft_putstr_fd(" (Ray void)", 2);
	if (err.texture_args & ERRN_08)
		ft_putstr_fd(" (Ray wall)", 2);
	if (err.texture_args & ERRN_09)
		ft_putstr_fd(" (Ray player)", 2);
	if (err.texture_args & ERRN_10)
		ft_putstr_fd(" (Mini void)", 2);
	if (err.texture_args & ERRN_11)
		ft_putstr_fd(" (Mini wall)", 2);
	if (err.texture_args & ERRN_12)
		ft_putstr_fd(" (Mini player)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_texture_known(t_error err)
{
	if (err.texture & ERRN_02)
		error_print_texture_window(err);
	if (err.texture & ERRN_03)
		error_print_texture_load(err);
}
