# cub3d

[PDF](https://cdn.intra.42.fr/pdf/pdf/68043/en.subject.pdf)

## TODO

- fix little norme issue everywhere (line to long prototype)
  - inc/
  - src/
- add multiple texture to the cube face (parsing)
  - can have at least 1 to a lot :)
    - parsing -> t_texture_list
    - loading -> t_mlx_side -> t_mlx_texture

- eviter de deplacer player.pos en dehors de la map

## STATUS

:green_circle:				= done

:orange_circle:	= wip

:red_circle:						= not done

|Name      |done ?         | Desc                         |
|:--------:|:-------------:|:-----------------------------|
|parsing   |:green_circle: |                              |
|collision |:green_circle: |cannot pass throught wall     |
|runing    |:green_circle: |can run with shift            |
|          |               |                              |
|mini map  |:orange_circle:|display a minimap             |
|          |:green_circle: |- round map                   |
|          |:green_circle: |- protect outside map         |
|          |:green_circle: |- float centered by player pos|
|          |:green_circle: |- draw open/close door        |
|          |:green_circle: |- struct mini to included     |
|          |:orange_circle:|- fov + hit                   |
|          |:red_circle:   |- 'tab' to expand map         |
|          |:red_circle:   |- 'M' to expand map           |
|          |               |                              |
|door      |:orange_circle:|door mechanism                |
|          |:green_circle: |- parse good wall in map      |
|          |:orange_circle:|- display doors               |
|          |:red_circle:   |- interact with door with kb  |
|          |               |                              |
|annimation|:orange_circle:|animation mechanism           |
|          |:orange_circle:|- parse multiple texture      |
|          |:red_circle:   |- animate                     |


## tips

> show diff betwen two dir, with colors
`diff --color=always -bur ./src/mandatory/ ./src/bonus | less -r`

> launch ft_helper, add -g3 disable -Werror
`make DEBUG=1`

> run mandatory maps
`make MAP=<MAP_PATH> run`

> run bonus maps
`make MAP=<MAP_PATH> run_bonus`
