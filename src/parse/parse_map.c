/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssubielo <ssubielo@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:24:02 by ssubielo          #+#    #+#             */
/*   Updated: 2022/12/23 17:24:03 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int check_is_line_in_map(char *line, unsigned char *in_map)
{
    int i;

    i = 0;
    while (ft_isblank(line[i]))
        i++;
    if ((!line[i]) && *in_map == 1)
    {
        *in_map = 2;
        return (1);
    }
    else if (line[i] && *in_map == 2)
        return(2);
    else if (line[i] && *in_map == 0)
    {
        *in_map = 1;
        return (-1);
    }
    return (-1);
}

int check_is_line_is_map(char *line, unsigned char *player)
{
    int i;

    i = 0;
    while (ft_isblank(line[i]))
        i++;
    while (line[i])
    {
        if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'S') \
             && *player == 0)
            *player = 1;
        else if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'S') \
             && *player == 1)
            return (1);
        else if (line[i] != '1' && line[i] != '0' && line[i]  != ' ' && line[i]  != '\n')
            return (2);
        i++;
    }
    return(-1);
}

int    fill_map(char *line, t_parse *main)
{
	char **new_map;
	int i;

	if (!main->map)
		main->map = ft_calloc(1, sizeof(char *));
    if (!main->map)
		return (1);
    i = 0;
	while (main->map[i])
		i++;
	new_map = ft_calloc(i + 2, sizeof(char *));
	if (!new_map)
		return (1);
	i = 0;
	while (main->map[i])
	{
		new_map[i] = main->map[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
        return (1);
    free(main->map);
	main->map = new_map;
    return (-1);
}

int parse_map(char *line, t_parse *main)
{
    int i;
    int state;
    static unsigned char player = 0;
    static unsigned char in_map = 0;

    i = 0;
    if (!line && in_map == 0) 
        return(17);
    else if(!line && player == 0)
        return(16);
    else if(!line)
        return(-1); 
    state = check_is_line_in_map(line, &in_map);
    if (state == 2)
        return (12);
    else if (state == 1)
        return (0);
    state = check_is_line_is_map(line, &player);
    if (state == 1)
        return (13);
    else if (state == 2)
        return (14);
    while (ft_isblank(line[i]))
        i++;
    if (in_map == 1)
    {
        if (fill_map(line,main) == 1)
            return (15);
    }
    if (in_map == 2 && player == 0)
        return(16);
    return (0);
}