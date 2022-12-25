/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 16:33:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_permission(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	return (file);
}

char	*get_line(int file)
{
	char	*ptr;
	int		last_char_index;

	ptr = ft_get_next_line(file);
	if (ptr)
	{
		last_char_index = ft_strlen(ptr) - 1;
		if (ptr[last_char_index] == '\n')
			ptr[last_char_index] = 0;
	}
	debug_print(PARSE_LINE, (void *)ptr);
	return (ptr);
}

int	parse_file_params(int file, t_parse *main)
{
	char	*line;
	int		return_value;

	line = get_line(file);
	if (!line)
		return (4);
	return_value = parse_line(line, main);
	if (return_value == 1)
		debug_print(PARSE_EMPTY_LINE, FT_NULL);
	else if (return_value)
		return (return_value);
	while (line)
	{
		free(line);
		line = get_line(file);
		return_value = parse_line(line, main);
		if (return_value == 1)
			debug_print(PARSE_EMPTY_LINE, FT_NULL);
		else if (return_value == -1)
			break ;
		else if (return_value)
			return (return_value);
	}
	return (0);
}

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

void	create_check_wall(char *check_map, int w)
{
	int i;

	i = 0;
	while (i < w + 4)
	{
		check_map[i] = '1';
		i++;
	}
}

void	create_space_check_wall(char *check_map, int w)
{
	int i;

	i = 0;
	while (i < w + 4)
	{
		check_map[i] = ' ';
		i++;
	}
	check_map[0] = '1';
	check_map[w + 3] = '1';
}

void	init_check_map(char **check_map, int h, int w)
{
	int i;

	i = 0;
	while (i < h + 4)
	{
		if (i == 0 || i == h + 3)
			create_check_wall(check_map[i], w);
		else if (i == 1 || i == h + 2)
			create_space_check_wall(check_map[i], w);
		else
		{
			check_map[i][0] = '1';
			check_map[i][1] = ' ';
			check_map[i][w + 2] = ' ';
			check_map[i][w + 3] = '1';
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
	init_check_map(check_map, h, w);
	fill_check_map(map ,check_map, h, w);
	return (check_map);
}

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

int	parse_file_map(t_parse *main)
{
	int r_value;

	char **check_map;
	check_map = create_check_map(main->map);
	if (!check_map)
		return(15);
	r_value = check_map_is_good(check_map);
	if (r_value)
	{
		ft_free_char_pp(check_map);
		return(12);
	}
	ft_free_char_pp(main->map);
	main->map = check_map;
	return (-1);
}

int	parse_file(char *filename, t_parse *main)
{
	int		file;
	int		return_value;

	file = check_permission(filename);
	if (file < 0)
		return (3);
	return_value = parse_file_params(file, main);
	if (return_value && return_value != -1)
		return (return_value);
	return_value = parse_file_map(main);
	return (return_value);
}
