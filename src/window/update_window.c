/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssubielo <ssubielo@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:31:24 by ssubielo          #+#    #+#             */
/*   Updated: 2023/01/11 17:31:26 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

void	ft_put_pixel(int x, int y, t_image *image, unsigned char rgb[3])
{
	image->buff[(int)(x * 4 + 4 * y * image->img_x + 2)] = (int)(rgb[0]);
	image->buff[(int)(x * 4 + 4 * y * image->img_x + 1)] = (int)(rgb[1]);
	image->buff[(int)(x * 4 + 4 * y * image->img_x)] = (int)(rgb[2]);
}

void    draw_back_ground(unsigned char floor[3], unsigned char ceiling[3], t_image *scene)
{
    int i;
    int j;

    i = 0;
    while (i <= scene->img_y / 2)
	{
        j = 0;
		while (j <= scene->img_x)
		{
			ft_put_pixel(j, i, scene, ceiling);
			j++;
		}
		i++;
	}
    while (i <= scene->img_y)
	{
        j = 0;
		while (j <= scene->img_x)
		{
			ft_put_pixel(j, i, scene, floor);
			j++;
		}
		i++;
	}
}

void	rigth_ray(t_ray *ray, t_player player)
{
    if (ray->ra > P2 && ray->ra < P3)
	{
		ray->rx = (((int)player.pos_x>> 6) << 6) - 0.001;
		ray->ry = (player.pos_x - ray->rx)*ray->ntan + player.pos_y;
		ray->xo = -64;
		ray->yo = -ray->xo * ray->ntan;
	}
}

void	left_ray(t_ray *ray, t_player player)
{
	if (ray->ra < P2 || ray->ra > P3)
	{
		ray->rx = (((int)player.pos_x>> 6) << 6) + 64;
		ray->ry = (player.pos_x - ray->rx)*ray->ntan + player.pos_y;
		ray->xo = 64;
		ray->yo = -ray->xo * ray->ntan;
	}
}

void	vertical_ray(t_ray *ray, t_player player, t_map map)
{
    ray->dof = 0;
	ray->ntan = -tan(ray->ra);
    rigth_ray(ray, player);
    left_ray(ray, player);
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = player.pos_x;
		ray->ry = player.pos_y;
		ray->dof = map.matrix_x + 6;
	}
	while (ray->dof < map.matrix_x + 6)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		if (ray->mx >= 0 && ray->my >= 0 &&  ray->mx < map.matrix_x  && ray->my < map.matrix_y && map.matrix[ray->my][ray->mx] == '1')
		{
			ray->dof = map.matrix_x + 6;
			ray->hit = 1;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
}

void	up_ray(t_ray *ray, t_player player)
{
    if (ray->ra > PI )
    {
        ray->ry = (((int)player.pos_y>> 6) << 6) - 0.001;
	    ray->rx = (player.pos_y - ray->ry)*ray->atan + player.pos_x;
	    ray->yo = -64; 
	    ray->xo = -ray->yo * ray->atan;
    }
}

void	down_ray(t_ray *ray, t_player player)
{
    if (ray->ra < PI )
    {
        ray->ry = (((int)player.pos_y>> 6) << 6) + 64;
	    ray->rx = (player.pos_y - ray->ry)*ray->atan + player.pos_x;
	    ray->yo = 64;
	    ray->xo = -ray->yo * ray->atan;
    }
}

void	horizontal_ray(t_ray *ray, t_player player, t_map map)
{
    ray->dof = 0;
    ray->atan = -1/tan(ray->ra);
    up_ray(ray, player);
    down_ray(ray, player);
    if (ray->ra == 0 || ray->ra == PI)
    {
			ray->rx = player.pos_x;
			ray->ry = player.pos_y;
			ray->dof = map.matrix_y + 6;
	}
    while (ray->dof < map.matrix_y + 6)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		if (ray->mx >= 0 && ray->my >= 0 &&  ray->mx < map.matrix_x  && ray->my < map.matrix_y  && map.matrix[ray->my][ray->mx] == '1')
		{
			ray->dof = map.matrix_y + 6;
			ray->hit = 1;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
    ray->sy = ray->ry;
	ray->sx = ray->rx;
	ray->dist = sqrt(((ray->rx - player.pos_x) * (ray->rx - player.pos_x)) + ((ray->ry - player.pos_y) * (ray->ry - player.pos_y)));
}

void add_ray(t_ray *ray, t_image scene)
{
    ray->ra += DR / (scene.img_x / 60);
	if (ray->ra < 0)
		ray->ra += 2 * PI;
	if (ray->ra > 2 * PI)
		ray->ra -= + 2 * PI;
	ray->r++;
}

void init_ray(t_ray *ray, t_player player , t_image scene)
{
    ray->r = 0;
	ray->ra = player.angle - DR * 30;
	if (ray->ra < 0)
		ray->ra += 2 * PI;
	if (ray->ra > 2 * PI)
		ray->ra -= + 2 * PI;
	ray->n_r = scene.img_x;
	ray->dist = 100000;
}

void choose_ray(t_ray *ray, t_player player, t_map map)
{
	if (ray->dist > sqrt(((ray->rx - player.pos_x) * (ray->rx - player.pos_x)) + ((ray->ry - player.pos_y) * (ray->ry - player.pos_y))))
	{
		ray->dist = sqrt(((ray->rx - player.pos_x) * (ray->rx - player.pos_x)) + ((ray->ry - player.pos_y) * (ray->ry - player.pos_y)));
		ray->sy = ray->ry;
		ray->sx = ray->rx;
		if (ray->rx < player.pos_x)
			ray->img_use = map.n_texture;
		else
			ray->img_use = map.s_texture;
		ray->tx = (int)(ray->sy)%64;
	}
	else
	{
		if (ray->ry < player.pos_y)
			ray->img_use = map.e_texture;
		else
			ray->img_use = map.w_texture;
		ray->tx = (int)(ray->sx)%64;
	}
}

void fix_fisheyes(t_ray *ray, t_player player)
{
	ray->ca = player.angle - ray->ra;
	if(ray->ca < 0)
		ray->ca += 2 * PI;
	if (ray->ca > 2 * PI)
		ray->ca -= 2*PI;
	ray->dist *= cos(ray->ca);
}

void set_line_height(t_ray *ray, t_image scene)
{
	ray->line_h = (64 * scene.img_x) / ray->dist;
	ray->ty_step = ray->img_use.img_y/(float)ray->line_h;
	ray->ty_off = 0;
	if (ray->line_h > scene.img_y)
	{
		ray->ty_off = (ray->line_h - scene.img_y) / 2.0;
		ray->line_h = scene.img_y;
	}
}

int	check_in_img(t_ray ray, t_image scene)
{
	(void)scene;
	if ((int)ray.tx * 4 + 4 * (int)ray.ty * ray.img_use.img_x < 0)
		return(0);
	return(1);
}

void draw_wall(t_map map, t_player player, t_image *scene)
{
    t_ray ray;

	int i;

	init_ray(&ray, player, *scene);
	while (ray.r < ray.n_r)
	{
		ray.hit = 0;
		horizontal_ray(&ray, player, map);
		vertical_ray(&ray, player, map);
		choose_ray(&ray, player, map);
		if (ray.hit == 1 && ray.dist < sqrt(((0 - map.matrix_x*64) * (0 - map.matrix_x*64)) + ((0 - map.matrix_y*64) * (0 - map.matrix_y*64))))
		{
			fix_fisheyes(&ray, player);
			set_line_height(&ray, *scene);
			i = 0;
			ray.ty = ray.ty_off*ray.ty_step;
			while(i < ray.line_h)
			{
				if (check_in_img(ray, *scene))
				{
					ray.color[0] = ray.img_use.buff[(int)(ray.img_use.img_x*ray.tx/64) * 4 + 4 * (int)ray.ty * ray.img_use.img_x + 2];
					ray.color[1] = ray.img_use.buff[(int)(ray.img_use.img_x*ray.tx/64) * 4 + 4 *(int)ray.ty * ray.img_use.img_x + 1];
					ray.color[2] = ray.img_use.buff[(int)(ray.img_use.img_x*ray.tx/64) * 4 + 4 *(int)ray.ty * ray.img_use.img_x];
					ft_put_pixel((int)ray.r, (int)(i + (scene->img_y / 2 - ray.line_h/2)), scene, ray.color);
				}
				ray.ty += ray.ty_step;
				i++;
			}
		}
		add_ray(&ray, *scene);
	}
}

void    update_window(t_frame *frame)
{
    draw_back_ground(frame->map.floor, frame->map.ceiling, &frame->scene);
    draw_wall(frame->map, frame->player, &frame->scene);
    mlx_put_image_to_window(frame->mlx, frame->win, frame->scene.img , 0, 0);
}
