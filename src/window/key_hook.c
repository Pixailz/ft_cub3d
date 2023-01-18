/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssubielo <ssubielo@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:53:09 by ssubielo          #+#    #+#             */
/*   Updated: 2023/01/11 21:53:10 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

void rotate_left(t_player *player)
{
    player->angle -= 0.1;
	if (player->angle < 0)
		player->angle += 2 * PI;
	player->dx = cos(player->angle) * 1;
	player->dy = sin(player->angle) * 1;
}

void rotate_rigth(t_player *player)
{
    player->angle += 0.1;
	if (player->angle > 2 * PI)
	    player->angle -=  (2 * PI);
	player->dx = cos(player->angle) * 1;
	player->dy = sin(player->angle) * 1;
}

void translate_front(t_player *player)
{
    player->pos_x += player->dx;
	player->pos_y += player->dy;
}

void translate_back(t_player *player)
{
    player->pos_x -= player->dx;
	player->pos_y -= player->dy;
}

int	check_button_press(int button, t_frame *frame)
{	
	if (button == XK_w)
	{
		translate_front(&frame->player);
		while ((int)(frame->player.pos_x / 64) >= 0 && (int)(frame->player.pos_y) / 64 >= 0 && (int)(frame->player.pos_x / 64) < frame->map.matrix_x && (int)(frame->player.pos_y / 64) < frame->map.matrix_y && frame->map.matrix[(int)(frame->player.pos_y / 64)][(int)(frame->player.pos_x / 64)] == '1')
			translate_front(&frame->player);
	}
	else if(button == XK_s)
	{
        translate_back(&frame->player);
		while ((int)(frame->player.pos_x / 64) >= 0 && (int)(frame->player.pos_y) / 64 >= 0 && (int)(frame->player.pos_x / 64) < frame->map.matrix_x && (int)(frame->player.pos_y / 64) < frame->map.matrix_y && frame->map.matrix[(int)(frame->player.pos_y / 64)][(int)(frame->player.pos_x / 64)] == '1')
			translate_back(&frame->player);
	}
	else if(button == XK_a)
        rotate_left(&frame->player);
	else if(button == XK_d)
        rotate_rigth(&frame->player);
	else
		return(0);
	if ((int)(frame->player.pos_x / 64) >= 0 && (int)(frame->player.pos_y) / 64 >= 0 && (int)(frame->player.pos_x / 64) < frame->map.matrix_x && (int)(frame->player.pos_y / 64) < frame->map.matrix_y && frame->map.matrix[(int)(frame->player.pos_y / 64)][(int)(frame->player.pos_x / 64)] != ' ') 
		draw_back_ground(frame->map.floor, frame->map.ceiling, &frame->scene);
	draw_wall(frame->map, frame->player, &frame->scene);
	mlx_put_image_to_window(frame->mlx, frame->win, frame->scene.img,0,0);
	mlx_destroy_image(frame->mlx, frame->scene.img);
	frame->scene.img = mlx_new_image(frame->mlx, frame->scene.img_x, frame->scene.img_y);
	frame->scene.buff = mlx_get_data_addr(frame->scene.img, &frame->scene.bpp, &frame->scene.size_line, &frame->scene.endian);
	return (0);
}