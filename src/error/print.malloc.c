/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 22:52:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_malloc(t_r_value return_value)
{
	ft_put_padded_str(2, 1, "Malloc:");
	if (return_value & ERRN_01)
		ft_put_padded_str(2, 1, ERRN_MALLOC_STR_01);
	ft_putchar_fd('\n', 2);
}
