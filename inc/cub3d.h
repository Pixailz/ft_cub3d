/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 13:41:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "mlx.h"
# include "libft.h"
# include <errno.h>
# include <string.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef DEBUG
#  define DEBUG 1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD 420
# endif

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_parse
{
	int				file;
	unsigned char	floor[3];
	unsigned char	ceiling[3];
	int				north_file;
	int				south_file;
	int				west_file;
	int				east_file;
	char			**map;
}				t_parse;

/*tmp for main vomie*/

typedef struct s_ray
{
	int r;
	int n_r;
	int	mx;
	int	my;
	int ca;
	int	map_x;
	int	map_y;
	int	mp;
	int	dof;
	float rx;
	float ry;
	float sx;
	float sy;
	float ra;
	float xo;
	float yo;
} t_ray;


typedef struct s_player
{
	float pos_y;
	float pos_x;
	float dx;
	float dy;
	float angle;
	float fov_rad;
} t_player;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buff;
	int		img_y;
	int		img_x;
	int		map_y;
	int		map_x;
	int		bpp;
	int		size_line;
	int		endian;
	t_player player;
	char	**map;
	unsigned char *floor;
	unsigned char *ceiling;
} t_window;
/*tmp for main vomie*/

// typedef struct s_config
// {
// }				t_parse;

enum e_debug_type
{
	PARSE_LINE,
	PARSE_EMPTY_LINE
};

enum e_param_type
{
	NO	= 1,
	SO	= 1 << 1,
	WE	= 1 << 2,
	EA	= 1 << 3,
	F	= 1 << 4,
	C	= 1 << 5,
};

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// debug/debug.c
void	debug_print(int mode, void *ptr);

// debug/parsing.1.c
void	debug_parse(char *ptr);

// error/parse_error.c
int		parsing_error(int return_code);
void	parsing_error_parameters(int return_code);
void	parsing_error_texture_type(int line_type);

// free/free.c
int		free_entry(t_parse *main);

// init_entry.c
void	init_entry(t_parse *main);

// main.c
int		check_button_press(int button, t_window *window);
int		ft_close(t_window *window);
int		get_x_size(char *map);
int		get_y_size(char **map);
void	draw_map(t_window *window);
void	draw_pixel(t_window *window , int x , int y,unsigned char rgb[3]);
void	draw_player(t_window *window);
void	draw_square(t_window *window , int x[2] , int y[2], unsigned char rgb[3]);
void	ft_put_pixel(int x, int y, t_window *window, unsigned char rgb[3]);
void	set_player_pos(t_window *window);
void draw_ray(t_window *window);
void reder_2d_test(t_parse *main);

// parse/check_map_parsing/create_check_map.c
char **calloc_check_map(int h, int w);
char **create_check_map(char **map);
void	get_map_size(char **map, int *h, int *w);
void	init_check_map(char **check_map, int h, int w , char bord);
void fill_check_map(char **map ,char **check_map, int h, int w);

// parse/check_map_parsing/verif_check_map.c
int		check_map_is_good(char **check_map);
int check_map_error(char **check_map, int i, int j);

// parse/parse_entry.c
int		parse_entry(char *filename, t_parse *main);
int		parse_file_name(char *filename);

// parse/parse_file.c
char	*get_line(int file);
int		check_permission(char *filename);
int		parse_file(char *filename, t_parse *main);
int		parse_file_map(t_parse *main);
int		parse_file_params(int file, t_parse *main);

// parse/parse_line.c
int		parse_get_line_type(char *line);
int		parse_is_good_line(char *line, t_parse *main);
int		parse_line(char *line, t_parse *main);
t_bool	parse_is_line_already_taken(int already_taken, int line_type);

// parse/parse_line_color.c
int		check_line_color(char *ptr, int line_type, t_parse *main);
int		parse_line_color(char *line, int line_type, t_parse *main);

// parse/parse_line_texture.c
int		parse_line_texture(char *line, int line_type, t_parse *main);
t_bool	ft_is_space(const char c);

// parse/parse_map.c
int    fill_map(char *line, t_parse *main);
int check_is_line_in_map(char *line, unsigned char *in_map);
int check_is_line_is_map(char *line, unsigned char *player);
int parse_map(char *line, t_parse *main);

/* ########################################################################## */

#endif
