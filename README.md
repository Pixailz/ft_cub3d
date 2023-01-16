# cub3d

[PDF](https://cdn.intra.42.fr/pdf/pdf/68043/en.subject.pdf)

# TODO

- fix texture bug
  - new_buff or reset scene buff
- minimap ?
- review parsing

# utils command

> create all texture needed
`touch path_to_the_{north,south,east,west}_texture`

```c

typedef struct s_ray
{
	int		nbr
	int		depth_of_field;
	t_pos	pos;
	float	angle;
	float	a_tan;
	float	n_tan;
}				t_ray;

int r,mxmy,mp, dof;
float ray_x, ray_y,ray_angle,xo,yo;
```
