/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 22:00:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_args_map(t_error *error)
{
	ft_putendl_fd("Map:", 2);
	if (error->args & ERRN_13)
		ft_putendl_fd(ERRN_ARGS_STR_13, 2);
	if (error->args & ERRN_14)
		ft_putendl_fd(ERRN_ARGS_STR_14, 2);
	if (error->args & ERRN_15)
		ft_putendl_fd(ERRN_ARGS_STR_15, 2);
	if (error->args & ERRN_16)
		ft_putendl_fd(ERRN_ARGS_STR_16, 2);
	if (error->args & ERRN_17)
		ft_putendl_fd(ERRN_ARGS_STR_17, 2);
	if (error->args & ERRN_18)
		ft_putendl_fd(ERRN_ARGS_STR_18, 2);
}
