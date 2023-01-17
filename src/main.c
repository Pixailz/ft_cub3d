/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:57:29 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 00:17:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# include <X11/X.h>
# include <X11/keysym.h>
#include <math.h>
#define PI 3.1415926535
#define P2 3.1415926535/2
#define P3 3*3.1415926535/2
#define DR 0.0174533

int	ft_close(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(0);
	return (0);
}

int	get_y_size(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return(i * 64);
}

int	get_x_size(char *map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return(i * 64);
}

void	ft_put_pixel(int x, int y, t_window *window, unsigned char rgb[3])
{
	window->buff[(int)(x * 4 + 4 * y * window->img_x + 2)] = (int)(rgb[0]);
	window->buff[(int)(x * 4 + 4 * y * window->img_x + 1)] = (int)(rgb[1]);
	window->buff[(int)(x * 4 + 4 * y * window->img_x)] = (int)(rgb[2]);
}

void	draw_square(t_window *window , int x[2] , int y[2], unsigned char rgb[3])
{
	int reset;
	reset = x[0];
	while (y[0] <= y[1])
	{
		x[0] = reset;
		while (x[0] <= x[1])
		{
			ft_put_pixel(x[0], y[0], window, rgb);
			x[0]++;
		}
		y[0]++;
	}
}

void	draw_pixel(t_window *window , int x , int y,unsigned char rgb[3])
{

	window->buff[(int)(x * 4 + 4 * y * window->img_x + 2)] = rgb[0];
	window->buff[(int)(x * 4 + 4 * y * window->img_x + 1)] = rgb[1];
	window->buff[(int)(x * 4 + 4 * y * window->img_x)] = 	rgb[2];
}

void draw_ray(t_window *window)
{
	t_ray ray;
	float atan;
	float ntan;
	float dist;
	float ty;
	float tx;
	float ty_step;
	float ty_off;
	int line_h;
	char *path_N = "./wallN.xpm";
	char *path_S = "./wallS.xpm";
	char *path_E = "./wall4.xpm";
	char *path_W = "./wallW.xpm";
	int	img_T_x;
	unsigned char color[3];
	int img_T_y;
	int img_T_endian;
	int img_T_bpp;
	void *img_N;
	void *img_S;
	void *img_E;
	void *img_W;

	char *img_N_buff;
	char *img_S_buff;
	char *img_E_buff;
	char *img_W_buff;

	char *img_use;
	int i;

	(void)img_N;
	(void)img_S;
	(void)img_E;
	(void)img_W;
	(void)img_use;
	(void)img_N_buff;
	(void)img_S_buff;
	(void)img_E_buff;
	(void)img_W_buff;
	img_T_x = 64;
	img_T_y = 64;
	ray.r = 0;
	img_N = mlx_xpm_file_to_image(window->mlx, path_N, &img_T_x,&img_T_y);
	if (img_N == NULL)
		ft_printf("ERROR\n");
	img_S = mlx_xpm_file_to_image(window->mlx, path_S, &img_T_x,&img_T_y);
	if (img_S == NULL)
		ft_printf("ERROR\n");
	img_E = mlx_xpm_file_to_image(window->mlx, path_E, &img_T_x,&img_T_y);
	if (img_E == NULL)
		ft_printf("ERROR\n");
	img_W = mlx_xpm_file_to_image(window->mlx, path_W, &img_T_x,&img_T_y);
	if (img_N == NULL)
		ft_printf("ERROR\n");
	img_N_buff = mlx_get_data_addr(img_N, &img_T_bpp, &img_T_x, &img_T_endian);
	if (img_N_buff == NULL)
		ft_printf("ERROR\n");
	img_S_buff = mlx_get_data_addr(img_S, &img_T_bpp, &img_T_x, &img_T_endian);
	img_E_buff = mlx_get_data_addr(img_E, &img_T_bpp, &img_T_x, &img_T_endian);
	img_W_buff = mlx_get_data_addr(img_W, &img_T_bpp, &img_T_x, &img_T_endian);
	ray.ra = window->player.angle - DR * 30;
	if (ray.ra < 0)
		ray.ra += 2 * PI;
	if (ray.ra > 2 * PI)
		ray.ra -= + 2 * PI;
	ray.n_r = window->img_x;
	dist = 100000;
	while (ray.r < ray.n_r)
	{
		ray.dof = 0;
		atan = -1/tan(ray.ra);
		if (ray.ra > PI )
		{
			ray.ry = (((int)window->player.pos_y>> 6) << 6) - 0.0001;
			ray.rx = (window->player.pos_y - ray.ry)*atan + window->player.pos_x;
			ray.yo = -64;
			ray.xo = -ray.yo*atan;
		}
		if (ray.ra < PI )
		{
			ray.ry = (((int)window->player.pos_y>> 6) << 6) + 64;
			ray.rx = (window->player.pos_y - ray.ry)*atan + window->player.pos_x;
			ray.yo = 64;
			ray.xo = -ray.yo*atan;
		}
		if (ray.ra == 0 || ray.ra == PI)
		{
			ray.rx = window->player.pos_x;
			ray.ry = window->player.pos_y;
			ray.dof = 64;
		}
		while (ray.dof < 64)
		{
			ray.mx = (int)(ray.rx) >> 6;
			ray.my = (int)(ray.ry) >> 6;
			if (ray.mx >= 0 && ray.my >= 0 &&  ray.mx < window->map_x - 1 && ray.my < window->map_y - 1 && window->map[ray.my][ray.mx] == '1')
				ray.dof = 64;
			else
			{
				ray.rx+=ray.xo;
				ray.ry+=ray.yo;
				ray.dof++;
			}
		}
		ray.sy = ray.ry;
		ray.sx = ray.rx;
		dist = sqrt(((ray.rx - window->player.pos_x) * (ray.rx - window->player.pos_x)) + ((ray.ry - window->player.pos_y) * (ray.ry - window->player.pos_y)));
		ray.dof = 0;
		ntan = -tan(ray.ra);
		if (ray.ra > P2 && ray.ra < P3)
		{
			ray.rx = (((int)window->player.pos_x>> 6) << 6) - 0.0001;
			ray.ry = (window->player.pos_x - ray.rx)*ntan + window->player.pos_y;
			ray.xo = -64;
			ray.yo = -ray.xo*ntan;
		}
		if (ray.ra < P2 || ray.ra > P3)
		{
			ray.rx = (((int)window->player.pos_x>> 6) << 6) + 64;
			ray.ry = (window->player.pos_x - ray.rx)*ntan + window->player.pos_y;
			ray.xo = 64;
			ray.yo = -ray.xo*ntan;
		}
		if (ray.ra == 0 || ray.ra == PI)
		{
			ray.rx = window->player.pos_x;
			ray.ry = window->player.pos_y;
			ray.dof = 64;
		}
		while (ray.dof < 64)
		{
			ray.mx = (int)(ray.rx) >> 6;
			ray.my = (int)(ray.ry) >> 6;
			if (ray.mx >= 0 && ray.my >= 0 &&  ray.mx < window->map_x - 1 && ray.my < window->map_y - 1 && window->map[ray.my][ray.mx] == '1')
				ray.dof = 64;
			else
			{
				ray.rx+=ray.xo;
				ray.ry+=ray.yo;
				ray.dof++;
			}
		}
		if ( dist > sqrt(((ray.rx - window->player.pos_x) * (ray.rx - window->player.pos_x)) + ((ray.ry - window->player.pos_y) * (ray.ry - window->player.pos_y))))
		{
			dist = sqrt(((ray.rx - window->player.pos_x) * (ray.rx - window->player.pos_x)) + ((ray.ry - window->player.pos_y) * (ray.ry - window->player.pos_y)));
			ray.sy = ray.ry;
			ray.sx = ray.rx;
			if (ray.rx < window->player.pos_x)
				img_use = img_N_buff;
			else
				img_use = img_S_buff;
			tx = (int)(ray.sy)%64;
		}
		else
		{
			if (ray.ry < window->player.pos_y)
				img_use = img_E_buff;
			else
				img_use = img_W_buff;
			tx = (int)(ray.sx)%64;
		}
		/*ray.ca = window->player.angle - ray.ra;
		if(ray.ca < 0)
			ray.ca += 2*PI;
		if (ray.ca > 2*PI)
			ray.ca -= 2*PI;
		dist *= cos(ray.ca);*/
		/*if (ray.r == window->img_y / 2)
			printf("%f\n",dist);*/
		//draw_square(window,(int[]){(int)ray.sx - 1, (int)ray.sx + 1 } , (int[]){(int)ray.sy - 1, (int)ray.sy + 1}, color);
		line_h = (64 * window->img_x) / dist;
		ty_step = 64.0/(float)line_h;
		ty_off = 0;
		if (line_h > window->img_y)
		{
			ty_off = (line_h - window->img_y) / 2.0;
			line_h = window->img_y;
		}
		i = 0;
		ty = ty_off*ty_step;
		while(i < line_h)
		{
			color[0] = img_use[(int)tx * 4 + 4 * (int)ty * 64 + 2];
			color[1] = img_use[(int)tx * 4 + 4 *(int)ty * 64 +1];
			color[2] = img_use[(int)tx * 4 + 4 *(int)ty* 64];
			draw_pixel(window,(int)ray.r, (int)(i +(window->img_y/2-line_h/2)), color);
			i++;
			ty += ty_step;
		}
		ray.ra += DR / (window->img_x / 60);
		if (ray.ra < 0)
			ray.ra += 2 * PI;
		if (ray.ra > 2 * PI)
			ray.ra -= + 2 * PI;
		ray.r++;

	}
	mlx_destroy_image(window->mlx, img_N);
}

void	draw_player(t_window *window)
{
	draw_square(window,(int[]){window->player.pos_x - 5 ,window->player.pos_x + 5}, (int[]){window->player.pos_y - 5, window->player.pos_y + 5}, (unsigned char[]){255,0,0});
	draw_square(window,(int[]){window->player.pos_x - 1, window->player.pos_x + 1}, (int[]){window->player.pos_y - 1, window->player.pos_y + 1}, (unsigned char[]){0,0,255});
	draw_ray(window);
}

void	draw_map(t_window *window)
{
	int i;
	int j;

	i = 0;
	j = 0;
	draw_square(window,(int[]){0, window->img_x} , (int[]){0, window->img_y}, (unsigned char[]){50,50,50});
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == '1')
				draw_square(window,(int[]){j * 64, j * 64 + 62} , (int[]){i * 64, i * 64 + 62}, (unsigned char[]){0,0,100});
			if (window->map[i][j] == '0' || ft_strcchr("ENSW", window->map[i][j]))
				draw_square(window,(int[]){j * 64 , j * 64 + 62 } , (int[]){i * 64 , i * 64 + 62 }, window->floor);
			j++;
		}
		i++;
	}
	draw_player(window);
	draw_ray(window);
}

int	check_button_press(int button, t_window *window)
{
	if (button == XK_w)
	{
		window->player.pos_x += window->player.dx;
		window->player.pos_y += window->player.dy;
	}
	else if(button == XK_s)
	{
		window->player.pos_x -= window->player.dx;
		window->player.pos_y -= window->player.dy;
	}
	else if(button == XK_a)
	{
		window->player.angle -= 0.1;
		if (window->player.angle < 0)
			window->player.angle += 2 * PI;
		window->player.dx = cos(window->player.angle) * 5;
		window->player.dy = sin(window->player.angle) * 5;
	}
	else if(button == XK_d)
	{
		window->player.angle += 0.1;
		if (window->player.angle > 2 * PI)
			window->player.angle -=  (2 * PI);
		window->player.dx = cos(window->player.angle) * 5;
		window->player.dy = sin(window->player.angle) * 5;
	}
	else
		return(0);
	draw_square(window,(int[]){0, window->img_x} , (int[]){0, window->img_y/2}, window->ceiling);
	draw_square(window,(int[]){0, window->img_x} , (int[]){window->img_y/2, window->img_y}, window->floor);
	draw_ray(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img,0,0);
	mlx_destroy_image(window->mlx, window->img);
	window->img = mlx_new_image(window->mlx, window->img_x, window->img_y);
	window->buff = mlx_get_data_addr(window->img, &window->bpp, &window->size_line, &window->endian);
	return (0);
}

void	set_player_pos(t_window *window)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (ft_strcchr("ENSW", window->map[i][j]))
			{
				window->player.pos_x = j * 64 + 32;
				window->player.pos_y = i * 64 + 32;
			}
			j++;
		}
		i++;
	}
}

void reder_2d_test(t_parse *main)
{
	t_window window;
	(void)main;

	window.map = main->map;
	window.floor = main->floor;
	window.ceiling = main->ceiling;
	window.player.angle = PI / 2;
	window.player.dx = cos(window.player.angle) * 5;
	window.player.dy = sin(window.player.angle) * 5;
	set_player_pos(&window);
	window.img_x = 1920;
	window.img_y = 1050;
	window.map_x = get_x_size(main->map[0]) / 64;
	window.map_y = get_y_size(main->map) / 64;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.img_x, window.img_y, "2D");
	window.img = mlx_new_image(window.mlx, window.img_x, window.img_y);
	window.buff = mlx_get_data_addr(window.img, &window.bpp, &window.size_line, &window.endian);
	draw_ray(&window);
	mlx_put_image_to_window(window.mlx, window.win, window.img,0,0);
	mlx_key_hook(window.win, &check_button_press, &window);
	mlx_hook(window.win, 17, 1L << 0, ft_close, &window);
	mlx_loop(window.mlx);
}

int	main(int argc, char **argv)
{
<<<<<<< HEAD
	t_main			config;

	if (argc != 2)
		return (ft_printf_fd(2, "Error: program take one arguments.\n"));
	init_config(&config);
	if (parse_entry(&config.err, argv[1], &config.parsing))
		return (error_print(config.err, &config));
	start_rendering(&config);
	error_print(config.err, &config);
	return (have_error(config.err, 0));
=======
	int			return_value;
	t_parse	main;

	if (argc != 2)
		return (ft_printf_fd(2, "Error: program take one arguments.\n"));
	init_entry(&main);
	return_value = parse_entry(argv[1], &main);
	if (return_value && return_value != -1)
		return (parsing_error(return_value));
	reder_2d_test(&main);
	free_entry(&main);
	return (0);
>>>>>>> origin/main
}
