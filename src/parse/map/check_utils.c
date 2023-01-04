/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:53:55 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 04:28:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	map_char_is_player(char c)
{
	if (c == 'N')
		return (TRUE);
	else if (c == 'S')
		return (TRUE);
	else if (c == 'E')
		return (TRUE);
	else if (c == 'W')
		return (TRUE);
	return (FALSE);
}
