/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 21:23:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_malloc(t_return_value return_value)
{
	ft_putstr_fd("Malloc: ", 2);
	if (return_value & ERRN_01)
		ft_putstr_fd(ERRN_MALLOC_STR_01, 2);
	ft_putchar_fd('\n', 2);
}
