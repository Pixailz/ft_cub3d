/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:06:13 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 08:21:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	init_entry(t_config *main)
{
	main->ceiling[0] = 0;
	main->ceiling[1] = 0;
	main->ceiling[2] = 0;
	main->floor[0] = 0;
	main->floor[1] = 0;
	main->floor[2] = 0;
}
