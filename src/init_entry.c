/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:06:13 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 14:24:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_entry(t_parse *main)
{
	main->map = NULL;
	main->ceiling[0] = 0;
	main->ceiling[1] = 0;
	main->ceiling[2] = 0;
	main->floor[0] = 0;
	main->floor[1] = 0;
	main->floor[2] = 0;
}
