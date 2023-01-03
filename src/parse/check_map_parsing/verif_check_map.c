/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssubielo <ssubielo@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:05:46 by ssubielo          #+#    #+#             */
/*   Updated: 2023/01/03 19:05:48 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int check_map_error(char **check_map, int i, int j)
{
	if (check_map[i][j] == ' ')
	{
		if (check_map[i][j + 1] != '1' && check_map[i][j + 1] != ' ')
			return(1);
		if (check_map[i][j - 1] != '1' && check_map[i][j - 1] != ' ')
			return(1);
		if (check_map[i + 1][j] != '1' && check_map[i + 1][j] != ' ')
			return(1);
		if (check_map[i - 1][j] != '1' && check_map[i - 1][j] != ' ')
			return(1);
	}
	return(0);
}

int	check_map_is_good(char **check_map)
{ 
	int i;
	int j;

	i = 0;
	j = 0;
	while (check_map[i])
	{
		j= 0;
		while (check_map[i][j])
		{
			if (check_map_error(check_map, i, j))
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}
