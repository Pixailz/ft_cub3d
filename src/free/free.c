/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:50:13 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 12:50:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	free_entry(t_parse *main)
{
	if (main->file >= 0)
		close(main->file);
	ft_free_char_pp(main->map);
	return (0);
}