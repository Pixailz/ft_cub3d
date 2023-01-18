/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssubielo <ssubielo@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:31:40 by ssubielo          #+#    #+#             */
/*   Updated: 2023/01/11 13:31:41 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

int	ft_close(t_frame *frame)
{
	mlx_destroy_image(frame->mlx, frame->scene.img);
	mlx_destroy_window(frame->mlx, frame->win);
	mlx_destroy_display(frame->mlx);
	free(frame->mlx);
	exit(0);
	return (0);
}


void	search_player(t_map map, int *i, int *j)
{
	while (map.matrix[*i])
	{
		*j = 0;
		while (map.matrix[*i][*j])
		{
			if (ft_strcchr("ENSW", map.matrix[*i][*j]))
				return;
			++*j;
		}
		++*i;
	}
}

void	init_player(t_player *player, t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	search_player(map, &i, &j);
	player->pos_x = j * 64 + 32;
	player->pos_y = i * 64 + 32;
	if (map.matrix[i][j] == 'N')
		player->angle = PI / 2;
	else if (map.matrix[i][j] == 'S')
		player->angle = 3 * PI / 3;
	else if (map.matrix[i][j] == 'W')
		player->angle = PI;
	else
		player->angle = 0;
	player->dx = cos(player->angle) * 20;
	player->dy = sin(player->angle) * 20;

}

void init_map(t_map *map, t_parse *main, t_frame *frame)
{
	/*tmp*/
	char *N = "./default_64x64_east.xpm";
	char *S = "./default_64x64_north.xpm";
	char *W = "./default_64x64_south.xpm";
	char *E = "./default_64x64_west.xpm";
	/*tmp*/
	map->matrix = main->map;
	map->floor = main->floor;
	map->ceiling = main->ceiling;
	map->n_texture.img = mlx_xpm_file_to_image(frame->mlx, N, &map->n_texture.img_x, &map->n_texture.img_y);
	map->s_texture.img = mlx_xpm_file_to_image(frame->mlx, S, &map->s_texture.img_x, &map->s_texture.img_y);
	map->w_texture.img = mlx_xpm_file_to_image(frame->mlx, W, &map->w_texture.img_x, &map->w_texture.img_y);
	map->e_texture.img = mlx_xpm_file_to_image(frame->mlx, E, &map->e_texture.img_x, &map->e_texture.img_y);
	map->n_texture.buff = mlx_get_data_addr(map->n_texture.img, &map->n_texture.bpp , &map->n_texture.size_line, &map->n_texture.endian);
	map->s_texture.buff = mlx_get_data_addr(map->s_texture.img, &map->s_texture.bpp , &map->s_texture.size_line, &map->s_texture.endian);
	map->w_texture.buff = mlx_get_data_addr(map->w_texture.img, &map->w_texture.bpp , &map->w_texture.size_line, &map->w_texture.endian);
	map->e_texture.buff = mlx_get_data_addr(map->e_texture.img, &map->e_texture.bpp , &map->e_texture.size_line, &map->e_texture.endian);
	get_map_size(map->matrix, &map->matrix_y, &map->matrix_x);
}

void init_frame_and_scene(t_frame *frame, t_image *scene)
{
	scene->img_x = 1920;
	scene->img_y = 1050;
	frame->win = mlx_new_window(frame->mlx, scene->img_x, scene->img_y, "Cub3d");
	frame->input = 1;
	scene->img = mlx_new_image(frame->mlx, scene->img_x, scene->img_y);
	scene->buff = mlx_get_data_addr(scene->img, &scene->bpp, &scene->size_line, &scene->endian);
}

void 	window(t_parse *main)
{
	t_frame frame;
	(void)main;

	frame.mlx = mlx_init();
	init_map(&frame.map, main, &frame);
	init_player(&frame.player, frame.map);
	init_frame_and_scene(&frame, &frame.scene);
	update_window(&frame);
	mlx_key_hook(frame.win, &check_button_press, &frame);
	mlx_hook(frame.win, 17, 1L << 0, ft_close, &frame);
	mlx_loop(frame.mlx);
}