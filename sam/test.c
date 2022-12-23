# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
#include <stdio.h>

typedef struct s_color
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}		t_color;

typedef struct s_texture
{
	char	*dest_text_up;
	char	*dest_text_down;
	char	*dest_text_left;
	char	*dest_text_rigth;
}		t_texture;

typedef struct s_map_param
{
	int			fd;
	t_texture	texture;
	t_color		floor_color;
	t_color		roof_color;
	char		**map;
}		t_map_param;


char	*double_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s1;

	s1 = (char *)s;
	while (n > 0)
	{
		s1[n - 1] = c;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = 0;
	if ((nmemb >= 65535 && size >= 65535))
		return (NULL);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen((char *) s);
	ptr = 0;
	if (start > size)
		len = 0;
	if (len > size - start)
		len = size - start;
	ptr = ft_calloc(sizeof(char), len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (start < start + len--)
		ptr[i++] = s[start++];
	return (ptr);
}

char	*ft_add_buf(char *save, int fd, int *endf)
{
	char	*buf;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	buf = ft_calloc(sizeof(char), 10);
	if (!buf)
		return (NULL);
	*endf = read(fd, buf, 10);
	if (*endf == -1)
		return (double_free(save, buf));
	str = ft_calloc(sizeof(char), (ft_strlen(save) + ft_strlen(buf)) + 1);
	if (!str)
		return (double_free(save, buf));
	while (save[++i])
		str[i] = save[i];
	while (buf[++j])
		str[i++] = buf[j];
	free(buf);
	free(save);
	return (str);
}

char	*ft_ini_line(char *save, size_t len)
{
	char	*line;
	size_t	i;

	if (!save)
		return (NULL);
	line = 0;
	line = ft_calloc(sizeof(char), len + 2);
	if (!line)
	{
		free(save);
		return (NULL);
	}
	i = -1;
	while (++i <= len)
		line[i] = save[i];
	return (line);
}

char	*ft_ini_save(char *save, unsigned int start)
{
	char	*new_save;
	int		len;
	size_t	i;
	size_t	size;

	if (!save)
		return (NULL);
	size = ft_strlen(save);
	new_save = 0;
	len = size - start;
	new_save = ft_calloc(sizeof(char), len + 2);
	if (!new_save)
		return (NULL);
	i = 0;
	while (start < start + len--)
		new_save[i++] = save[start++];
	free(save);
	return (new_save);
}

char	*ft_ini_buf(char *save, int *i, int fd)
{
	int	endf;

	endf = 1;
	while (save[++*i] != '\n' && endf)
	{
		if (!save[*i])
		{
			save = ft_add_buf(save, fd, &endf);
			--*i;
			if ((!endf && save[0] == 0) || endf == -1)
			{
				free(save);
				return (NULL);
			}
		}
	}
	return (save);
}

int		get_next_line(int fd, char *line)
{
	static char	*save;
	int			i;

	i = -1;
	line[0] = 0;
	if (!save)
	{
		save = ft_calloc(sizeof(char), 1);
		if (!save)
			return (0);
	}
	save = ft_ini_buf(save, &i, fd);
	if (!save)
		return (0);
	line[0] = ft_ini_line(save, i);
	if (!line[0])
		return (0);
	save = ft_ini_save(save, i + 1);
	if (!save)
		return (0);
	return (1);
}

int	ft_get_map_fd(char *file)
{
	int i;
	int fd;

	i = 0;
	while (file[i])
		i++;
	if (i < 5)
	{
		perror("Not a .cub file");
		exit(1);
	}
	if (file[i - 4] != '.' || file[i - 3] != 'c' || file[i - 2] != 'u' || file[i - 1] != 'b')
	{
		perror("Not a .cub file");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Can't open the file");

	}
	return (fd);
}

void ft_free_map(char **map)
{
	int i;

	i = 0;
	if(map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
}

void ft_free_texture(t_texture *texture)
{
	if (texture->dest_text_up)
	{
		free(texture->dest_text_up);
		texture->dest_text_up = NULL;
	}
	if (texture->dest_text_down)
	{
		free(texture->dest_text_down);
		texture->dest_text_down = NULL;
	}
	if (texture->dest_text_left)
	{
		free(texture->dest_text_left);
		texture->dest_text_left = NULL;
	}
	if (texture->dest_text_rigth)
	{
		free(texture->dest_text_rigth);
		texture->dest_text_rigth = NULL;
	}
}

void ft_free_map_param(t_texture *texture, char **map)
{
	ft_free_texture(texture);
	ft_free_map(map);
}

int	ft_return_rgb(const char *line, t_map_param *map_param, char id)
{
	int	i;
	int	value;

	value = 0;
	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		value = value * 10;
		value = value + line[i] - '0';
		i++;
	}
	if (i > 3 || value > 255 || !i)
	{
		if (id == 'C')
			perror("Wrong format : color range for identifier: C");
		else
			perror("Wrong format : color range for identifier: F");
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(1);
	}
	return (value);
}

int	ft_get_next_color(char *line, t_map_param *map_param, int i, int id)
{
	while (line[i] >= '0' && line[i] <= '9')
			i++;
	if (line[i] != ',' && line[i] != '\n')
	{
		if (id == 'C')
			perror("Wrong format : color range for identifier: C");
		else
			perror("Wrong format : color range for identifier: F");
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(1);
	}
	return (i);
}

void	ft_get_color_range(char *line, t_map_param *map_param, char id)
{
	int	i;

	i = 0;
	if (id == 'C')
	{
		map_param->roof_color.red = ft_return_rgb(line + i, map_param, id);
		i = ft_get_next_color(line, map_param, i, id);
		i++;
		map_param->roof_color.green = ft_return_rgb(line + i, map_param, id);
		i = ft_get_next_color(line, map_param, i, id);
		i++;
		map_param->roof_color.blue = ft_return_rgb(line + i, map_param, id);
	}
	else
	{
		map_param->floor_color.red = ft_return_rgb(line + i, map_param, id);
		i = ft_get_next_color(line, map_param, i, id);
		i++;
		map_param->floor_color.green = ft_return_rgb(line + i, map_param, id);
		i = ft_get_next_color(line, map_param, i, id);
		i++;
		map_param->floor_color.blue = ft_return_rgb(line + i, map_param, id);
	}
}

int	ft_check_color_id(char *line, t_map_param *map_param)
{
	int i;
	char id;

	i = 0;
	if (line[i] == 'C'  || line[i] == 'F')
	{
		id = line[i];
		while (line[i] == ' ' && line[i])
			i++;
		if (!line[i])
		{
			if (id == 'C')
				perror("Missing : color range for identifier: C");
			else
				perror("Missing : color range for identifier: F");
			ft_free_map_param(&map_param->texture, map_param->map);
			exit(1);
		}
		ft_get_color_range(line + i + 2, map_param, id);
		return(0);
	}
	return(1);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[++i] != 0)
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

void	ft_secure_malloc(char *str, t_map_param *map_param)
{
	if (!str)
	{
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(1);
	}
}

void	ft_secure_malloc_doubl(char **str, t_map_param *map_param)
{
	if (!str)
	{
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(1);
	}
}

void	ft_set_texture(char *line, t_map_param *map_param, char id)
{
	if (id == 'N')
	{
		map_param->texture.dest_text_up = ft_substr(line ,0, ft_strlen(line) - 1);
		ft_secure_malloc(map_param->texture.dest_text_up, map_param);
	}
	else if (id == 'S')
	{
		map_param->texture.dest_text_down = ft_substr(line ,0, ft_strlen(line) - 1);
		ft_secure_malloc(map_param->texture.dest_text_down, map_param);
	}
	else if (id == 'W')
	{
		map_param->texture.dest_text_left = ft_substr(line ,0, ft_strlen(line) - 1);
		ft_secure_malloc(map_param->texture.dest_text_left, map_param);
	}
	else if (id == 'E')
	{
		map_param->texture.dest_text_rigth = ft_substr(line ,0, ft_strlen(line) - 1);
		ft_secure_malloc(map_param->texture.dest_text_rigth, map_param);
	}
}
void	ft_get_texture(char *line, t_map_param *map_param, char id)
{
	int i;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	if (!line[i])
	{
		if (id == 'N')
			perror("Missing : texture path for identifier: NO");
		else if (id == 'S')
			perror("Missing : texture path for identifier: SO");
		else if (id == 'W')
			perror("Missing : texture path for identifier: WE");
		else if (id == 'E')
			perror("Missing : texture path for identifier: EA");
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(1);
	}
	ft_set_texture(line + i, map_param, id);
}

int	ft_check_texture_id(char *line, t_map_param *map_param)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		ft_get_texture(line + 2, map_param, 'N');
		return(0);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		ft_get_texture(line + 2, map_param, 'S');
		return(0);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		ft_get_texture(line + 2, map_param, 'W');
		return(0);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		ft_get_texture(line + 2, map_param, 'E');
		return(0);
	}
	return(1);
}

int	ft_check_map_char(char *line, int *player)
{
	int		i;
	char	c;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		c = line[i];
		if (!player)
		{
			printf("oui\n");
			if (c != '1' && c != '0' && c != ' ')
				if (c != 'E' && c != 'N' && c != 'S' && c != 'W')
					return (0);
		}
		else if (*player == 0)
		{
			if (c != '1' && c != '0' && c != ' ')
			{
				if (c != 'E' && c != 'N' && c != 'S' && c != 'W')
					return (1);
				else
					*player = 1;
			}
		}
		else if (*player == 1)
		{
			if (c != '1' && c != '0' && c != ' ')
				return (1);
		}
		i++;
	}
	if (!player)
		return (1);
	else
		return (0);
}

void	ft_file_map(char *line, t_map_param *map_param)
{
	static int player;
	char **new_map;
	int i;

	i = 0;
	if(ft_check_map_char(line, &player))
	{
		perror("Wrong format : wrong char fond in the map");
		free(line);
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(1);
	}
	if (!map_param->map)
	{
		map_param->map = ft_calloc(1, sizeof(char *));
		if (!map_param->map)
		{
			free(line);
			ft_free_map_param(&map_param->texture, map_param->map);
			exit(0);
		}
	}
	while (map_param->map[i])
		i++;
	new_map = ft_calloc(i + 2, sizeof(char *));
	if (!new_map)
	{
		free(line);
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(0);
	}
	i = 0;
	while (map_param->map[i])
	{
		new_map[i] = map_param->map[i];
		i++;
	}
	new_map[i] = ft_substr(line ,0, ft_strlen(line) - 1);
	if (!new_map[i])
	{
		free(new_map);
		free(line);
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(0);
	}
	free(map_param->map);
	map_param->map = new_map;
}

void	ft_check_line(char *line, t_map_param *map_param, int *nb_id)
{
	int i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	printf("|%c|\n",line[i]);
	if (line[i] == '\n')
		return;

	printf("%d\n",*nb_id);
	printf("%s",line);
	if (line[i + 1] == ' ' && *nb_id < 6)
	{
		++*nb_id;
		if(ft_check_color_id(line, map_param))
		{
			if(ft_check_map_char(line, NULL))
				perror("Wrong format : id not found");
			else
				perror("Wrong format : part of the map not fond at his place");
			ft_free_map_param(&map_param->texture, map_param->map);
			exit(1);
		}
	}
	else if (line[i + 2] == ' ' && *nb_id < 6)
	{
		++*nb_id;
		if (ft_check_texture_id(line, map_param))
		{
			if(ft_check_map_char(line, NULL))
				perror("Wrong format : id not found");
			else
				perror("Wrong format : part of the map not fond at his place");
			ft_free_map_param(&map_param->texture, map_param->map);
			exit(1);
		}
	}
	else if (*nb_id < 6)
	{
		if(ft_check_map_char(line, NULL))
			perror("Wrong format : id not found");
		else
			perror("Wrong format : part of the map not fond at his place");
		ft_free_map_param(&map_param->texture, map_param->map);
		exit(1);
	}
	else
		ft_file_map(line, map_param);
}

int		ft_get_max_width(char **map,int *heigth)
{
	int max_width;
	int j;

	max_width = 0;
	*heigth = 0;
	while (map[*heigth])
	{
		j = 0;
		while (map[*heigth][j])
		{
			if (j + 1 > max_width && map[*heigth][j] != ' ')
				max_width = j + 1;
			j++;
		}
		++*heigth;
	}
	return (max_width);
}

void	ft_create_w(char **check_map, t_map_param *map_param, int *i, int w)
{
	check_map[*i] = ft_calloc(w + 5, sizeof(char));
	if (!check_map[*i])
	{
		ft_free_texture(&map_param->texture);
		ft_free_map(map_param->map);
		while(*i >= 0)
		{
			free(check_map[*i]);
			--*i;
		}
		free(check_map);
		exit(1);
	}
	++*i;
}

void	ft_fill_check_map(char **check_map, char **map, int h, int w)
{
	int i;
	int j;

	(void)map;
	i = 0;
	while (i < h + 4)
	{
		j = 0;
		while (j < w + 4)
		{
			if (i == 0 || i == h + 3 || j == 0 || j == w + 3)
				check_map[i][j] = '1';
			else
				check_map[i][j] = ' ';
			j++;
		}
		i++;
	}
	j = 0;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (map[i][j] && j < w)
		{
			check_map[i + 2][j + 2] = map[i][j];
			j++;
		}
		while (j < w)
		{
			check_map[i + 2][j + 2] = ' ';
			j++;
		}
		i++;
	}
	i = 0;
	while (check_map[i])
	{
		printf("%s\n",check_map[i]);
		i++;
	}
	i = 0;
	j = 0;
	while (check_map[i])
	{
		j = 0;
		while (check_map[i][j])
		{
			if (check_map[i][j] == ' ')
			{
				if (check_map[i][j + 1] != '1' && check_map[i][j + 1] != ' ')
				{
					perror("NOP1");
					exit(1);
				}
				if (check_map[i][j - 1] != '1' && check_map[i][j - 1] != ' ')
				{
					perror("NOP2");
					exit(1);
				}
				if (check_map[i + 1][j] != '1' && check_map[i + 1][j] != ' ')
				{
					perror("NOP3");
					exit(1);
				}
				if (check_map[i - 1][j] != '1' && check_map[i - 1][j] != ' ')
				{
					perror("NOP4");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

char	**ft_create_check_map(t_map_param *map_param, int h, int w)
{
	char **check_map;
	int i;

	i = 0;
	check_map = ft_calloc(h + 5, sizeof(char *));
	ft_secure_malloc_doubl(check_map, map_param);
	while (i < h + 4)
		ft_create_w(check_map, map_param, &i, w);
	ft_fill_check_map(check_map, map_param->map, h, w);
	return(check_map);
}

void	ft_check_map(t_map_param *map_param)
{
	int max_width;
	int heigth;
	char **check_map;

	max_width = ft_get_max_width(map_param->map, &heigth);
	check_map = ft_create_check_map(map_param, heigth, max_width);
	(void)check_map;
}

void	ft_check_and_init_map_param(t_map_param *map_param)
{
	char	*line;
	int		error;
	int		nb_id;

	nb_id = 0;
	line = calloc(2,sizeof(char *));
	ft_secure_malloc_doubl(line, map_param);
	error = get_next_line(map_param->fd, line);
	while (error == 1)
	{
		if (line[0][0] != '\n')
			ft_check_line(line[0], map_param, &nb_id);
		free(line[0]);
		error = get_next_line(map_param->fd, line);
	}
	free(line[0]);
	free(line);
	close(map_param->fd);
	ft_check_map(map_param);
}

void	ft_set_param_to_zero(t_map_param *map_param)
{
	map_param->fd = 0;
	map_param->texture.dest_text_up = NULL;
	map_param->texture.dest_text_down = NULL;
	map_param->texture.dest_text_rigth = NULL;
	map_param->texture.dest_text_left = NULL;
	map_param->map = NULL;
}

int main(int ac, char **av)
{
	t_map_param	map_param;
	int i;

	i = 0;
    if (ac > 2)
	{
		perror("To many arguments");
		exit(1);
	}
	else if (ac < 2)
	{
		perror("No arguments");
		exit(1);
	}
	ft_set_param_to_zero(&map_param);
	map_param.fd = ft_get_map_fd(av[1]);
	ft_check_and_init_map_param(&map_param);
	printf("dest_text_NO = %s\n", map_param.texture.dest_text_up);
	printf("dest_text_SO = %s\n", map_param.texture.dest_text_down);
	printf("dest_text_WE = %s\n", map_param.texture.dest_text_left);
	printf("dest_text_EA = %s\n", map_param.texture.dest_text_rigth);
	printf("rgb top = %d,%d,%d\n", map_param.roof_color.red, map_param.roof_color.green,  map_param.roof_color.blue);
	printf("rgb botom = %d,%d,%d\n\n", map_param.floor_color.red, map_param.floor_color.green,  map_param.floor_color.blue);
	printf("               map\n");
	printf("                |\n");
	printf("                V\n\n");
	while (map_param.map[i])
	{
		printf("%s\n",map_param.map[i]);
		i++;
	}
	ft_free_map_param(&map_param.texture, map_param.map);
}
