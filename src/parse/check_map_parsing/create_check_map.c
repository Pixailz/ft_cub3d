/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssubielo <ssubielo@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:05:32 by ssubielo          #+#    #+#             */
/*   Updated: 2023/01/03 19:05:33 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_map_size(char **map, int *h, int *w)
{
	int j;

	*w = 0;
	*h = 0;
	while (map[*h])
	{
		j = 0;
		while (map[*h][j])
		{
			if (j + 1 > *w && map[*h][j] != ' ')
				*w = j + 1;
			j++;
		}
		++*h;
	}
}

char **calloc_check_map(int h, int w)
{
	int i;
	char **check_map;

	i = 0;
	check_map = ft_calloc(sizeof(char *), h + 5);
	if (!check_map)
		return(NULL);
	while(i < h + 4)
	{
		check_map[i] = ft_calloc(sizeof(char *), w + 5);
		if (!check_map[i])
		{
			i = 0;
			while (check_map[i])
			{
				free(check_map[i]);
				i++;
			}
			free(check_map);
			return(NULL);
		}
		i++;
	}
	return(check_map);
}

void	init_check_map(char **check_map, int h, int w , char bord)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < h + 4)
	{
		j = 0;
		while (j < w + 4)
		{
			if (i == 0 || i == h + 3 || j == 0 || j == w + 3)
				check_map[i][j] = bord;
			else if (i == 1 || i == h + 2 || j == 1 || j == w + 2)
				check_map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void fill_check_map(char **map ,char **check_map, int h, int w)
{
	int i;
	int j;

	i = 2;
	while (i < h + 2)
	{
		j = 2;
		while (map[i - 2][j - 2] && j < w + 2)
		{
			check_map[i][j] = map[i - 2][j - 2];
			j++;
		}
		if (j < w + 2)
		{
			while (j < w + 2)
			{
				check_map[i][j] = ' ';
				j++;
			}
		}
		i++;
	}
}

char **create_check_map(char **map)
{
	int w;
	int h;
	char **check_map;

	get_map_size(map, &h, &w);
	check_map = calloc_check_map(h, w);
	if (!check_map)
		return(NULL);
	init_check_map(check_map, h, w, '1');
	fill_check_map(map ,check_map, h, w);
	return (check_map);
}

