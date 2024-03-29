/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 06:44:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

/* mlx_destroy_image()
 * mlx_destroy_window()
 * mlx_put_image_to_window()
 * mlx_new_window()
 * mlx_get_data_addr()
 * mlx_xpm_file_to_image()
 * mlx_hook()
 * mlx_init()
 */
# include "mlx.h"
# include "libft.h"
/* strerror()
 */
# include <string.h>
/* sqrt()
 * double
 * float
 */
# include <math.h>
/* usleep()
 */
# include <unistd.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

// DEBUG
# ifndef DEBUG
#  define DEBUG							1
# endif

# ifndef VERBOSE
#  define VERBOSE						1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD						420
# endif

// MATH
	// ONE DEGREE
# define DR								0.0174533
	// PI, THE ONLY ONE
# define PI								3.1415926535
	// 2xPI
# define PI2							6.2831853072
	// (3xPI)/2
# define PI3							4.7123889804
	// PI/2
# define PI4							1.5707963268
	// ONE second in micro second
# define ONE_SEC						1000000

// CONFIG
	// BASE
# define PLAYER_STEP					0.036
# define SHIFTING_SPEED					5
# define TURN_SENSIVITY					0.8
# define FOV							50
# define FPS							144
# define FOG							8
# define RATIO_FOG						0.6
# define FULL_SCREEN					FALSE
# define MOUSE_ENABLE					TRUE
# define RAY_ENABLE						FALSE
# define COLLISION						TRUE
# define FRAME_INTERVAL					10

	// MATRIX
# define MAX_DOF						1
# define GOOD_CHAR_MAP					" 10NSWED"
# define VOID_CHAR						' '
# define WALL_CHAR						'1'
# define EMPTY_CHAR						'0'
# define DOOR_CLOSE_CHAR				'D'
# define DOOR_OPEN_CHAR					'd'

	// WINDOW
# define WINDOW_TITLE					"Supa Cub3D"
# define SCREEN_SIZE_X					1024
# define SCREEN_SIZE_Y					576
// # define SCREEN_SIZE_X					1920
// # define SCREEN_SIZE_Y					1080
// # define SCREEN_SIZE_X					1600
// # define SCREEN_SIZE_Y					900

	// KEYBOARD
		// DEFAULT
# define KEY_A							0x61
# define KEY_W							0x77
# define KEY_S							0x73
# define KEY_D							0x64
# define KEY_E							0x65
# define KEY_M							0x6d
# define KEY_TAB						0xff09
# define KEY_LSHIFT						0xffe1

		// ARROW
# define KEY_RIGHT						0xff53
# define KEY_LEFT						0xff51

		// EXTRA
# define KEY_ESC						0xff1b

	// RAYCAST
# define PLAYER_ANGLE_SIZE				16
# define PLAYER_ANGLE_COLOR				0x00ff00

		// TEXTURE
# define RAY_HIT_COLOR					0xff0000

	// MINIMAP
		// TEXTURE
# define MINI_WALL_PATH					"./rsc/xpm/minimap/wall_x16.xpm"
# define MINI_VOID_PATH					"./rsc/xpm/minimap/void_x16.xpm"
# define MINI_PLAYER_PATH				"./rsc/xpm/minimap/player_x5.xpm"
# define MINI_DOOR_CLOSE_PATH			"./rsc/xpm/minimap/door_close_x16.xpm"
# define MINI_DOOR_OPEN_PATH			"./rsc/xpm/minimap/door_open_x16.xpm"
# define MINI_EDGE_COLOR				0xff00
# define MINI_EDGE_TRESH				2

		// POSITION
			// NORMAL MODE
# define MINI_CENTER_X					100
# define MINI_CENTER_Y					100
// # define MINI_CENTER_X					500
// # define MINI_CENTER_Y					300
# define MINI_CIRCLE_RADIUS				90

			// EXPANDED MODE
# define MINI_EXPANDED_CENTER_X			200
# define MINI_EXPANDED_CENTER_Y			200
# define MINI_EXPANDED_CIRCLE_RADIUS	180

// ERRNO
# define ERRN_LENGTH					32

	// MASK
# define ERRN_MASK_INPUT_USER			0x1f
# define ERRN_MASK_KNOWN				0xfe0
# define ERRN_MASK_MAP					0xff000
# define ERRN_MASK_TEXTURE_ARG			0x6

	// STRING
# define PADDING_STR					"   "

		// MALLOC
# define ERRN_MALLOC_STR_01		"inside gnl"
# define ERRN_MALLOC_STR_02		"inside split"
# define ERRN_MALLOC_STR_03		"inside get_map()"
# define ERRN_MALLOC_STR_04		"inside dup_map_squared()"
# define ERRN_MALLOC_STR_05		"texture list"
# define ERRN_MALLOC_STR_06		"texture array"

		// PARAMS
# define ERRN_PARAMS_STR_01		"file path too short"
# define ERRN_PARAMS_STR_02		"wrong file extension"
# define ERRN_PARAMS_STR_04		"empty file (argv[1])"
# define ERRN_PARAMS_STR_05		"unknown parameter"
# define ERRN_PARAMS_STR_06		"parameter already provided"
# define ERRN_PARAMS_STR_07		"wrong parameter seperator (spaces(' '), only)"
# define ERRN_PARAMS_STR_08		"parameter cannot be empty"
# define ERRN_PARAMS_STR_10		"wrong color format"
# define ERRN_PARAMS_STR_11		"non numeric number provided"
# define ERRN_PARAMS_STR_12		"wrong number"
# define ERRN_PARAMS_STR_13		"no map provided"
# define ERRN_PARAMS_STR_14		"contain empty line ('\\n' only)"
# define ERRN_PARAMS_STR_15		"wrong char in map"
# define ERRN_PARAMS_STR_16		"not surrounded"
# define ERRN_PARAMS_STR_17		"have multiple player"
# define ERRN_PARAMS_STR_18		"don't have player"
# define ERRN_PARAMS_STR_19		"have door(s) not surrounded"
# define ERRN_PARAMS_STR_20		"have door(s) obstructed"

		// TEXTURE
# define ERRN_TEXTURE_STR_01	"init mlx failed"
# define ERRN_TEXTURE_STR_02	"init window failed"
# define ERRN_TEXTURE_STR_03	"load texture"
# define ERRN_TEXTURE_STR_04	"load scene"

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT / DEFINE */
/* ############### */

typedef unsigned long					t_r_value;

enum	e_errno
{
	ERRN_00 = 0,
	ERRN_01 = 1U,
	ERRN_02 = 1U << 1,
	ERRN_03 = 1U << 2,
	ERRN_04 = 1U << 3,
	ERRN_05 = 1U << 4,
	ERRN_06 = 1U << 5,
	ERRN_07 = 1U << 6,
	ERRN_08 = 1U << 7,
	ERRN_09 = 1U << 8,
	ERRN_10 = 1U << 9,
	ERRN_11 = 1U << 10,
	ERRN_12 = 1U << 11,
	ERRN_13 = 1U << 12,
	ERRN_14 = 1U << 13,
	ERRN_15 = 1U << 14,
	ERRN_16 = 1U << 15,
	ERRN_17 = 1U << 16,
	ERRN_18 = 1U << 17,
	ERRN_19 = 1U << 18,
	ERRN_20 = 1U << 19,
	ERRN_21 = 1U << 20,
	ERRN_22 = 1U << 21,
	ERRN_23 = 1U << 22,
	ERRN_24 = 1U << 23,
	ERRN_25 = 1U << 24,
	ERRN_26 = 1U << 25,
	ERRN_27 = 1U << 26,
	ERRN_28 = 1U << 27,
	ERRN_29 = 1U << 28,
	ERRN_30 = 1U << 29,
	ERRN_31 = 1U << 30,
	ERRN_32 = 1U << 31,
};

enum e_debug_type
{
	ERROR_PRINT_ERRN,
	PARSE_RETURN_VALUE,
	PARSE_LINE,
	PARSE_EMPTY_LINE,
	PARSE_PARAMS_DONE,
	PARSE_GET_MAP,
	PARSE_GET_MAP_SPLITTED,
	PARSE_MAP_COORD_CHECKED,
	PARSE_GET_MAP_SURROUDED,
	PARSE_MAP_SIZE,
	RENDER_SCREEN_SIZE,
	RENDER_KEY_PRESS,
	RENDER_KEY_RELEASE,
	RENDER_PLAYER,
	RENDER_LINE,
	RAY_HORIZONTAL,
	RAY_VERTICAL
};

typedef enum e_param_type
{
	OTHER			= 0,
	NORTH			= 1L,
	SOUTH			= 1L << 1,
	WEST			= 1L << 2,
	EAST			= 1L << 3,
	FLOOR			= 1L << 4,
	CEIL			= 1L << 5,
	MAIN_WINDOW		= 1L << 6,
	MINI_VOID		= 1L << 7,
	MINI_WALL		= 1L << 8,
	MINI_PLAYER		= 1L << 9,
	MINI_DOOR_CLOSE	= 1L << 10,
	MINI_DOOR_OPEN	= 1L << 11
}	t_param_type;

typedef struct s_error
{
	t_r_value	malloc;
	t_r_value	params;
	t_r_value	params_args;
	t_r_value	texture;
	t_r_value	texture_args;
}	t_error;

typedef struct s_d_pos
{
	double	x;
	double	y;
}	t_d_pos;

typedef struct s_i_pos
{
	int	x;
	int	y;
}	t_i_pos;

typedef struct s_l_pos
{
	long int	x;
	long int	y;
}	t_l_pos;

typedef struct s_ll_pos
{
	long long int	x;
	long long int	y;
}	t_ll_pos;

typedef struct s_line
{
	t_d_pos	begin;
	t_d_pos	end;
	t_int4	color;
}	t_line;

typedef struct s_circle
{
	int		radius;
	t_i_pos	center;
	t_int4	color;
}	t_circle;

typedef struct s_mlx_texture
{
	void		*ptr;
	char		*buff;
	int			bpp;
	int			endian;
	int			size_line;
	t_i_pos		len;
}	t_mlx_texture;

typedef struct s_mlx_a_text
{
	t_mlx_texture	*frame;
	t_mlx_texture	*current_frame;
	int				frame_nb;
	int				frame_id;
}				t_mlx_a_text;

typedef struct s_mlx_textures
{
	t_mlx_a_text	north;
	t_mlx_a_text	south;
	t_mlx_a_text	west;
	t_mlx_a_text	east;
	t_mlx_texture	mini_wall;
	t_mlx_texture	mini_void;
	t_mlx_texture	mini_player;
	t_mlx_texture	mini_door_close;
	t_mlx_texture	mini_door_open;
	t_mlx_texture	scene;
	int				frame_nb_max;
}	t_mlx_textures;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	void			*win_raycasting;
	int				frame_time;
	t_i_pos			screen;
	t_mlx_textures	textures;
}	t_mlx;

typedef struct s_ray
{
	int				nbr;
	int				nbr_ray;
	int				depth_of_field;
	int				bit_prec;
	int				text_size;
	int				mini_cell_size;
	int				mini_player_size;
	int				hit_door;
	int				ray_type;
	t_bool			hit;
	t_l_pos			max;
	t_d_pos			pos;
	t_d_pos			offset;
	t_d_pos			save;
	t_d_pos			t;
	float			angle;
	float			a_tan;
	float			n_tan;
	float			ty_step;
	float			ty_offset;
	int				t_height;
	double			dist;
	double			dist_real;
	t_mlx_texture	*img_use;
}	t_ray;

typedef struct s_file
{
	int			fd;
	int			err_no;
	char		*path;
}	t_file;

typedef struct s_file_l
{
	struct s_file_l	*next;
	t_file			file;
}					t_file_l;

typedef struct s_textures
{
	t_int4			floor;
	t_int4			ceiling;
	t_file_l		*north_file;
	t_file_l		*south_file;
	t_file_l		*west_file;
	t_file_l		*east_file;
}	t_textures;

typedef struct s_map
{
	t_file		file;
	t_l_pos		size;
	char		**matrix;
}	t_map;

typedef struct s_parse
{
	t_map		map;
	t_textures	textures;
	char		*current_line;
}	t_parse;

typedef struct s_move
{
	t_bool	up;
	t_bool	down;
	t_bool	left;
	t_bool	right;
	t_bool	left_angle;
	t_bool	right_angle;
	t_bool	up_angle;
	t_bool	down_angle;
	t_bool	shifting;
	t_bool	reading_map;
	t_d_pos	r_speed;
}	t_move;

typedef struct s_player
{
	t_d_pos	pos;
	t_d_pos	delta;
	t_d_pos	angle;
	t_move	movement;
}	t_player;

typedef struct s_minimap
{
	t_circle		circle;
	t_bool			zoomed;
	int				max_text_size;
	t_i_pos			max_dir;
	t_i_pos			max_dir_zoomed;
	t_i_pos			tmp_pos;
	t_i_pos			ppos;
	t_i_pos			ppos_scaled;
	t_i_pos			id;
	t_i_pos			dir;
	t_i_pos			img_2;
	t_mlx_texture	*img_to_use;
	t_mlx_texture	*wall;
	t_mlx_texture	*voidd;
	t_mlx_texture	*player;
	t_mlx_texture	*door_close;
	t_mlx_texture	*door_open;
}				t_minimap;

typedef struct s_main
{
	t_parse		parse;
	t_mlx		mlx;
	t_player	player;
	t_ray		ray;
	t_minimap	mini;
	t_error		err;
}	t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// dataset/free/config.c
void			free_config(t_main *config);

// dataset/free/file.c
void			close_file(int fd);
void			free_file(t_file *file);
void			free_file_list(t_file_l			*list);

// dataset/free/mlx.c
void			free_mlx(t_mlx *mlx, t_error err);
void			free_mlx_animated(t_mlx_a_text *text_a, void *mlx);
void			free_mlx_animated_entry(t_mlx *mlx);
void			free_mlx_texture(void *mlx, t_mlx_texture *text);
void			free_mlx_textures(t_mlx *mlx);

// dataset/free/mlx.hook.c
int				end_hook(t_mlx *mlx);

// dataset/free/parse.c
void			free_parse(t_parse *parse);

// dataset/free/texture.c
void			free_textures(t_textures *textures);

// dataset/init/config.c
void			init_config(t_main *config);

// dataset/init/file.c
void			init_file(t_file *file);
void			set_file(t_file *file, char *path, int fd);

// dataset/init/minimap.c
void			get_max_text_size(t_mlx_textures *text, t_minimap *mini, t_i_pos *max);
void			init_mini_map(t_main *config);

// dataset/init/mlx.c
t_r_value		init_mlx(t_main *config);
void			init_mlx_texture(t_mlx_texture *text);
void			init_mlx_textures(t_mlx_textures *textures);
void			init_mlx_window(t_mlx *mlx, t_error *err);

// dataset/init/mlx.hook.c
int				key_press(int key_code, t_main *config);
int				key_release(int key_code, t_main *config);
t_bool			is_movement_key(int key_code);
void			init_mlx_hook(t_main *config);
void			set_movement(t_move *movement, int key_code, t_bool value);

// dataset/init/mlx.hook.mouse.c
int				ft_get_axis(int x, int y, t_main *config);
int				ft_not_in_axis(t_main *config);

// dataset/init/parse.c
void			init_parse(t_parse *parse);

// dataset/init/player.c
float			get_player_angle_x(char player_char);
void			get_player_pos(t_map map, t_player *player, int text_size);
void			init_player(t_player *player);

// dataset/init/rendering.c
t_r_value		init_rendering(t_main *config);
t_r_value		start_rendering(t_main *config);

// dataset/init/texture.c
void			init_textures(t_textures *texture);

// debug/error.c
void			debug_print_errn(t_error *err);
void			debug_print_errn_binary(const char *title, t_int64 to_bin);
void			debug_print_error(int mode, void *ptr);

// debug/keypress.c
int				debug_print_key_letter(int key_code);
int				debug_print_key_special(int key_code);
void			debug_print_key(int key_code);

// debug/map.c
void			debug_print_coord_checked(t_i_pos pos, char **map);

// debug/parsing.c
void			debug_print_map_size(t_map *map);
void			debug_print_parse(int mode, void *ptr);
void			debug_print_splitted(char **splitted);
void			debug_print_surrounded(char **splitted);

// debug/print.c
void			debug_print(int mode, void *ptr);

// debug/ray.c
void			debug_print_ray(int mode, void *ptr);
void			debug_print_ray_info(char *title, t_ray ray);

// debug/render.c
void			debug_print_player_stat(t_player *player);
void			debug_print_render(int mode, void *ptr);
void			debug_print_screen_size(void *ptr);

// debug/render.line.c
void			debug_print_line_pos(t_line *line);

// error/print/entry.c
t_r_value		error_print(t_error err, t_main *config);
t_size			ft_put_padded(int fd, t_size lvl);
t_size			ft_put_padded_str(int fd, t_size lvl, const char *str);

// error/print/error_no_print.c
void			print_errno(t_file_l *text);

// error/print/malloc.c
void			error_print_malloc(t_r_value return_value);

// error/print/params.c
void			error_print_base(t_r_value params, int err_no);
void			error_print_params(t_error err, t_parse parse);
void			error_print_params_map(t_r_value params);

// error/print/params.color.c
void			error_print_params_color_format(t_r_value return_value);
void			error_print_params_color_non_numeric(t_r_value return_value);
void			error_print_params_color_wrong_number(t_r_value return_value);
void			error_print_params_wrong_color(t_error err);

// error/print/params.known.c
void			error_print_params_already_provided(t_r_value return_value);
void			error_print_params_have_empty(t_r_value return_value);
void			error_print_params_known(t_error err, t_parse parse);
void			error_print_params_wrong_path(t_r_value return_value, t_parse parse);
void			error_print_params_wrong_sep(t_r_value return_value);

// error/print/texture.c
void			error_print_texture(t_error err);

// error/print/texture.known.c
void			error_print_texture_known(t_error err);
void			error_print_texture_load(t_error err);
void			error_print_texture_window(t_error err);

// error/set/entry.c
t_r_value		set_error(t_error *err, unsigned char mode, t_r_value return_value);
t_r_value		set_error_known(t_error *err, int mode, t_r_value err_no, int type);
t_r_value		set_error_known_params(t_error *err, t_r_value err_no, int type);
t_r_value		set_error_known_texture(t_error *err, t_r_value err_no, int type);

// error/set/params.c
void			set_error_already_provided(int type, t_r_value *return_value);
void			set_error_have_empty(int type, t_r_value *return_value);
void			set_error_wrong_color(t_r_value err_no, int type, t_r_value *param_args);
void			set_error_wrong_path(int type, t_r_value *return_value);
void			set_error_wrong_sep(int type, t_r_value *return_value);

// error/set/texture.c
t_r_value		set_error_mlx_texture(t_param_type type, t_r_value *return_value);
t_r_value		set_error_mlx_window(t_param_type type, t_r_value *return_value);

// error/utils.c
t_bool			have_error(t_error err, int mode);
void			init_error(t_error *err);

// main.c

// parsing/dup_map_squared.c
char			**dup_map_squared(t_map map, int offset);
char			*dup_map_get_line(int width, char *line, int offset);
int				dup_map_get_surrounding(char **dup, int offset, t_map map);

// parsing/entry.c
int				parse_file(t_error *err, t_parse *parse, char *filename);
int				parse_file_name(t_error *err, char *filename);
t_r_value		parse_entry(t_error *err, char *filename, t_parse *parse);

// parsing/ft_cub3d_split.c
char			**ft_cub3d_split(char *str, char delim);
char			**ft_cub3d_split_get_words(char *str, char delim, int len_tab);
char			*ft_cub3d_get_word(char **str, char delim);

// parsing/line/color.c
int				check_line_color(t_error *err, char *ptr, int type, t_parse *parse);
int				parse_line_color(t_error *err, char *line, int type, t_parse *parse);

// parsing/line/entry.c
char			*parse_get_line(t_error *err, int file);
int				get_line_type(char *line);
int				is_good_line(t_error *err, char *line, t_parse *parse);
int				parse_line(t_error *err, char **line, t_parse *parse);
t_bool			have_all_params(int already_taken);

// parsing/line/file_list/list.c
int				lstsize_file(t_file_l *lst);
t_file_l		*lstnew_file(t_error *err, char *path, int fd);
void			lstadd_front_file(t_file_l **lst, t_file_l *new);

// parsing/line/texture.c
t_bool			ft_is_space(const char c);
t_r_value		parse_line_text(t_error *err, char *line, int type, t_parse *parse);
void			set_texture(t_error *err, t_file_l **text, char *path, int fd);

// parsing/map/check.door.surrounded.c
int				check_door(t_i_pos pos, char **map, t_error *err);
int				check_map_door_surrounded(t_map map, t_error *err);
t_bool			check_door_not_enclosed(t_i_pos pos, char **map);
t_bool			check_door_obstructed(t_i_pos pos, char **map);

// parsing/map/check.surrounded.c
t_bool			check_is_surrounded_char_4(t_i_pos pos, char **map);
t_bool			check_is_surrounded_char_8(t_i_pos pos, char **map);
t_bool			check_is_surrounded_map(t_error *err, t_map *map);

// parsing/map/content.c
int				check_map_content(t_map *map, t_error *err);
int				check_map_player_char(t_map map, t_error *err);
t_bool			check_map_new_line(t_map map);
t_bool			check_map_wrong_char(t_map map);

// parsing/map/entry.c
char			*get_current_line(t_error *err, t_parse *parse);
t_bool			get_map(t_error *err, t_parse *parse);
t_bool			get_map_end(t_error *err, char **tmp_joined, t_parse *parse);
t_r_value		parse_map(t_error *err, t_parse *parse);

// parsing/params.c
t_bool			parse_file_is_empty(t_error *err, char **line, int fd);
t_r_value		parse_file_params(t_error *err, t_parse *parse);

// parsing/utils.1.c
int				check_permission(char *filename);
t_bool			map_char_is_player(char c);
void			get_map_size(t_map *map);

// rendering/draw/fov.c

// rendering/draw/frame.c
int				draw_frame(t_main *config);
void			do_moving(t_main *config);
void			draw_background(t_main *config);
void			frame_id_process(t_main *config, int *frame_id);
void			put_background(t_int4 floor, t_int4 ceiling, t_mlx_texture *scene, t_player player);

// rendering/draw/hit.c
void			draw_ray_hit(t_main *config);

// rendering/draw/line.c
t_line			get_line(t_d_pos begin, t_d_pos end, t_int4 color);
void			draw_line(void *mlx_ptr, void *win_ptr, t_line line);

// rendering/draw/minimap/fov_draw.c
void			raycast_fov_draw(t_main *config, t_player player, t_ray ray_fov);
void			raycast_fov_draw_hit(t_main *config, t_player player, t_ray ray_fov);
void			raycast_fov_draw_line(t_main *config, t_player player, t_ray ray_fov);

// rendering/draw/minimap/fov_ray_horizontal.c
void			fov_cast_ray_down(t_ray *ray, t_player player);
void			fov_cast_ray_horizontal(t_ray *ray, t_player player, t_map map);
void			fov_cast_ray_up(t_ray *ray, t_player player);

// rendering/draw/minimap/fov_ray_vertical.c
void			fov_cast_ray_left(t_ray *ray, t_player player);
void			fov_cast_ray_right(t_ray *ray, t_player player);
void			fov_cast_ray_vertical(t_ray *ray, t_player player, t_map map);

// rendering/draw/minimap/fov_raycast.c
void			init_raycast_fov(t_ray *ray_fov, t_player *player, float angle, t_main *config);
void			raycast_fov(t_main *config, t_player player, t_ray *ray_fov);
void			raycast_fov_entry(t_main *config, float angle);

// rendering/draw/minimap/in_circle.c
t_bool			opti_outof_mini_square(int px, int py, t_circle circle);
t_bool			pos_is_in_circle(t_i_pos pos, int c_x, int c_y, t_circle circle);
void			ft_put_pixel_in_circle(t_i_pos pos, t_mlx_texture *image, t_int4 color, t_circle circle);
void			put_line_in_circle(t_mlx_texture *scene, t_line line, t_circle circle);
void			text_to_buff_circle(t_i_pos pos, t_mlx_texture *src, t_mlx_texture *dst, t_circle circle);

// rendering/draw/minimap/minimap.c
t_i_pos			get_max_dir(t_minimap mini);
void			draw_cross(t_main *config, t_circle circle);
void			draw_mini_map_scaled(t_main *config, t_minimap *mini);
void			draw_minimap(t_main *config);
void			minimap_choose_text(t_main *config, t_minimap *mini);

// rendering/draw/minimap/player.c
void			draw_minimap_player(t_main *config);
void			draw_minimap_player_angle(t_mlx_textures *text, t_minimap mini, float angle);
void			draw_minimap_player_square(t_mlx_textures *text, t_minimap mini);

// rendering/draw/minimap/update_minimap.c
void			update_mini_circle(t_bool zoomed, t_circle *circle);
void			update_mini_map(t_main *config, t_minimap *mini);
void			update_mini_map_vars(t_main *config, t_minimap *mini);

// rendering/draw/minimap/utils.c
char			get_current_char_map(t_map map, t_i_pos pos);
void			draw_circle(t_circle circle, t_mlx_textures *text);

// rendering/draw/raycast.c
void			draw_map(t_main *config);
void			draw_map_point(t_main *config, char current_cell, int y, int x);
void			draw_player_pos(t_main *config);
void			draw_raycast(t_main *config);

// rendering/draw/switch_textures.c
void			switch_texture(t_mlx_a_text *textures_a);
void			switch_textures(t_mlx_textures *textures);

// rendering/move/angle.c
void			adjust_delta(t_player *player, int text_size);
void			key_press_move_angle_down(t_player *player);
void			key_press_move_angle_left(t_player *player, int text_size);
void			key_press_move_angle_right(t_player *player, int text_size);
void			key_press_move_angle_up(t_player *player);

// rendering/move/dir.c
t_bool			hit_wall(t_player player, t_map map, int text_size);
t_d_pos			move_get_dir(t_player player);
void			move_dir_backward(t_player *player, int text_size, t_map map);
void			move_dir_forward(t_player *player, int text_size, t_map map);

// rendering/move/keypress.c
void			key_press_interact_down(t_main *config);
void			key_press_move_down(t_player *player, int text_size, t_map map);
void			key_press_move_left(t_player *player, int text_size, t_map map);
void			key_press_move_right(t_player *player, int text_size, t_map map);
void			key_press_move_up(t_player *player, int text_size, t_map map);

// rendering/raycast/cast.c
void			cast_ray_entry(t_main *config);
void			cast_rays(t_main *config);
void			choose_ray(t_main *config);
void			choose_ray_text(t_ray *ray, t_d_pos ppos, t_mlx_textures *text);

// rendering/raycast/get_text.c
t_int4			push_buff_scene_get_color(t_ray ray, int point);
void			fix_fisheyes(t_ray *ray, t_player player);
void			get_text(t_main *config);
void			push_buff_pixel_text(t_ray *ray, t_mlx_texture *scene, t_player player);
void			push_buff_scene_color(t_ray *ray, t_mlx_texture *scene, int counter, t_player player);
void			set_texture_height(t_ray *ray, t_mlx_texture scene, t_player player);

// rendering/raycast/horizontal.c
void			cast_ray_down(t_ray *ray, t_player player);
void			cast_ray_horizontal(t_ray *ray, t_player player, t_map map);
void			cast_ray_up(t_ray *ray, t_player player);

// rendering/raycast/vertical.c
void			cast_ray_left(t_ray *ray, t_player player);
void			cast_ray_right(t_ray *ray, t_player player);
void			cast_ray_vertical(t_ray *ray, t_player player, t_map map);

// rendering/texture/get.highest.c
t_i_pos			get_textures_highest_size(t_mlx_textures textures);
void			get_texture_highest_size(t_i_pos *highest, t_mlx_a_text textures_a);

// rendering/texture/load.animated.c
int				get_frame_nb_max(t_mlx_textures text);
int				load_texture_animated(t_mlx_a_text *text, t_file_l *file_l, int type, t_main *config);
int				load_textures_animated(t_main *config);

// rendering/texture/load.c
t_r_value		load_scene(t_main *config);
t_r_value		load_texture(t_mlx_texture *text, char *file_path, void *mlx);
t_r_value		load_textures(t_main *config);
void			load_textures_minimap(t_mlx *mlx, t_error *err);

// rendering/texture/load.size.c
unsigned char	get_bit_prec(int highest);
void			get_highest_size(t_i_pos *highest, t_mlx_texture text);
void			get_mini_size(t_main *config);
void			get_textures_size(t_main *config);

// rendering/utils.1.c
double			get_a_tan(double ray_angle);
double			get_dist(t_d_pos begin, t_d_pos end);
double			get_n_tan(double ray_angle);
t_bool			ray_hit(t_ray *ray, t_map map, int to_add);
void			increase_offset(t_ray *ray);

// rendering/utils.2.c
float			get_ratio(float nbr, t_ray ray);
int				check_in_img(t_ray ray, int point);
t_bool			pos_is_not_in_circle(t_i_pos pos, int c_x, int c_y, t_circle circle);
void			ft_put_pixel(int x, int y, t_mlx_texture *image, t_int4 color);
void			ft_put_pixel_not_in_circle(t_i_pos pos, t_mlx_texture *image, t_int4 color, t_circle circle);

/* ########################################################################## */

#endif
